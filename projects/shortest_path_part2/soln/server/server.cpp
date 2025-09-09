#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
#include <list>

#include "wdigraph.h"
#include "dijkstra.h"

struct Point {
    long long lat, lon;
};

// returns the manhattan distance between two points
long long manhattan(const Point& pt1, const Point& pt2) {
  long long dLat = pt1.lat - pt2.lat, dLon = pt1.lon - pt2.lon;
  return abs(dLat) + abs(dLon);
}

// finds the id of the point that is closest to the given point "pt"
int findClosest(const Point& pt, const unordered_map<int, Point>& points) {
  pair<int, Point> best = *points.begin();

  for (const auto& check : points) {
    if (manhattan(pt, check.second) < manhattan(pt, best.second)) {
      best = check;
    }
  }
  return best.first;
}

// read the graph from the file that has the same format as the "Edmonton graph" file
void readGraph(const string& filename, WDigraph& g, unordered_map<int, Point>& points) {
  ifstream fin(filename);
  string line;

  while (getline(fin, line)) {
    // split the string around the commas, there will be 4 substrings either way
    string p[4];
    int at = 0;
    for (auto c : line) {
      if (c == ',') {
        // start new string
        ++at;
      }
      else {
        // append character to the string we are building
        p[at] += c;
      }
    }

    if (at != 3) {
      // empty line
      break;
    }

    if (p[0] == "V") {
      // new Point
      int id = stoi(p[1]);
      assert(id == stoll(p[1])); // sanity check: asserts if some id is not 32-bit
      points[id].lat = static_cast<long long>(stod(p[2])*100000);
      points[id].lon = static_cast<long long>(stod(p[3])*100000);
      g.addVertex(id);
    }
    else {
      // new directed edge
      int u = stoi(p[1]), v = stoi(p[2]);
      g.addEdge(u, v, manhattan(points[u], points[v]));
    }
  }
}

int create_and_open_fifo(const char * pname, int mode) {
  // creating a fifo special file in the current working directory
  // with read-write permissions for communication with the plotter
  // both proecsses must open the fifo before they can perform
  // read and write operations on it
  if (mkfifo(pname, 0666) == -1) {
    cout << "Unable to make a fifo. Ensure that this pipe does not exist already!" << endl;
    exit(-1);
  }

  // opening the fifo for read-only or write-only access
  // a file descriptor that refers to the open file description is
  // returned
  int fd = open(pname, mode);

  if (fd == -1) {
    cout << "Error: failed on opening named pipe." << endl;
    exit(-1);
  }

  return fd;
}

// keep in mind that in part 1, the program should only handle 1 request
// in part 2, you need to listen for a new request the moment you are done
// handling one request
int main() {
    WDigraph graph;
    // a mapping between vertex identifiers and their
    // coordinates
    unordered_map<int, Point> points;

    const char *inpipe = "inpipe";
    const char *outpipe = "outpipe";

    // Open the two pipes
    int in = create_and_open_fifo(inpipe, O_RDONLY);
    cout << "inpipe opened..." << endl;
    int out = create_and_open_fifo(outpipe, O_WRONLY);
    cout << "outpipe opened..." << endl;

    // build the graph
    readGraph("server/edmonton-roads-2.0.1.txt", graph, points);

    // Start and endpoints for each of the way points
    Point sPoint, ePoint;

    // cstring used to read in the coordinates of the point
    char msg[22];

    // Char to hold the current character being read in
    char current;

    // Used to iterate through the msg cstring
    int idx;

    // We must iterate through the while loop twice per route request
    // Thus the conunter variable keeps track of the current iteration
    int counter = 0;

    string lat_s, lon_s, lat_e, lon_e;
    char delimator = '\n';
    char end_line = 'E';
    int start, end;

    string str_lat;
    string str_lon;

    // cstring to hold the latitude and longitude of waypoint along
    // the path of the route
    char char_lat[9];
    char char_lon[11];

    // Continue completely route request queries from the client until a
    // 'Q' character is read (indicating the user has exitied the program by
    // pressing the x button)
    // The server waits for the next request from the client as soon as
    // it answers a route request query
    while (true) {
        // Reset the index variable
        idx = 0;

        // If counter equals 2, the previous route request has been completed
        // and there is a new route request, thus we must reset counter to 0
        if (counter == 2) {
            counter = 0;
        }

        // Continue reading bytes from the in pipe until a \n character is read
        // from the pipe
        while (1) {
            read(in, &current, 1);
            if (current == '\n') {
                break;
            }
            // set msg at the current index to the current
            // byte and increment idx by 1
            msg[idx++] = current;
        }
        // Set the last character in msg to \0
        msg[idx] = '\0';

        // When msg equals "Q", the user has pressed the x botton in
        // the plotter program to exit the program, thus we break out
        // of the loop as there is no more route requests left
        if (strcmp(msg, "Q") == 0) {
            break;
        }

        // Store msg in a string
        string msg_str(msg);

        // For the first iteration, msg corresponds to the latitude and
        // longitude of the start point, thus we save the coodinates to
        // two strings. If counter is not 0, then we are on out second iteration
        // and must save the lat and lon of the end point
        if (counter == 0) {
            // The latiude is the first 9 characters of msg
            lat_s = msg_str.substr(0, 9);
            // The longitude is the last 11 characters of msg
            lon_s = msg_str.substr(10, 11);
            counter++;
        } else {
            // The latiude is the first 9 characters of msg
            lat_e = msg_str.substr(0, 9);
            // The longitude is the last 11 characters of msg
            lon_e = msg_str.substr(10, 11);
            counter++;
        }

        // We are on the second iteration and the coordinates of both start
        // and end points have been read in, the waypoints along the shortest
        // route can now be calculated and sent through the outpipe to
        // the client
        if (counter == 2) {
            // Initialize a new tree for each route request
            unordered_map<int, PIL> tree;

            // Convert each latitude and longitude of the start and end
            // point to a long long
            // The coordinates must be provided in 10000-ths of degrees
            sPoint.lat = static_cast<long long>(stod(lat_s)*100000);
            sPoint.lon = static_cast<long long>(stod(lon_s)*100000);
            ePoint.lat = static_cast<long long>(stod(lat_e)*100000);
            ePoint.lon = static_cast<long long>(stod(lon_e)*100000);

            // get the points closest to the two points we read
            start = findClosest(sPoint, points);
            end = findClosest(ePoint, points);

            // Run Dijkstra's algorithm
            dijkstra(graph, start, tree);

            // no path
            if (tree.find(end) == tree.end()) {
                // Just write out the character 'E' and
                // '\n' to the outpipe
                write(out, &end_line, 1);
                write(out, &delimator, 1);
            } else {
                // read off the path by stepping back through the search tree
                list<int> path;
                while (end != start) {
                    path.push_front(end);
                    end = tree[end].first;
                }
                path.push_front(start);

                // Iterate through all the waypoints of the shortest path
                // and write each waypoint to the outpipe
                for (int v : path) {
                    // Convert the lat and lon (which are both long long)
                    // to a string in order to write them out to the outpipe
                    str_lat = to_string(points[v].lat);
                    str_lon = to_string(points[v].lon);

                    // Insert the decimal point for the lat and lon
                    str_lat.insert(2, ".");
                    str_lon.insert(4, ".");

                    // convert the string to a cstring
                    strcpy(char_lat, str_lat.c_str());
                    strcpy(char_lon, str_lon.c_str());

                    // Write out the lat and long to the outpipe which a
                    // space character between them and a \n character at
                    // the end
                    write(out, char_lat, strlen(char_lat));
                    write(out, " ", 1);
                    write(out, char_lon, strlen(char_lon));
                    write(out, &delimator, 1);
            }
            // Every route request must end with the character 'E' and
            // a \n character after all waypoints for a route request
            // has been written to the outpipe
            write(out, &end_line, 1);
            write(out, &delimator, 1);
            }
        }
    }

    // Both pipes must be closed and unlinked
    // once the user has finished
    close(out);
    close(in);
    unlink(outpipe);
    unlink(inpipe);

    return 0;
}
