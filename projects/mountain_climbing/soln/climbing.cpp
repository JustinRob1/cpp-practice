#include <iostream>
#include <climits>

using namespace std;

// uint is another name for unsigned int defined using typedef
typedef unsigned int uint;

/* 
    Description: Finds the minimum value of burst such that you are able to reach the highest
    ledge in at most limit seconds

    Arguments: heights (const uint): Represents the heights of ledges on a cliff
    (in feet)
    length (uint): Represents the number of ledges on the mountain
    rest (uint): How many seconds you have to rest between climbing bursts
    limit (uint): How many seconds you have to climb the cliff

    Returns: The minimum value of burst
*/
uint climbing(const uint *heights, uint length, uint rest, uint limit) {
    // Burst tracks the minimum able to reach the top ledge in at most
    // limit time
    uint burst = UINT_MAX;

    // Tracks the time required to reach the top ledge
    uint time = 0;
    // when limit=heights[length - 1] we do not have time to rest on a ledge,
    // hence we must climb the cliff in one burst. This means that the minimum
    // value of burst would be heights[length - 1] in the worst case
    if (limit == heights[length - 1]) {
        return heights[length - 1];
    } else {
        // Set the high and low pointers as well as the mid point
        // to implement a divide and conquer strategy
        int high = length - 1;
        int low = 0;
        int mid = (high + low)/2;

        // Initalize time for the first iteration
        time += heights[mid];

        // Tank measures the maximum distance the climber
        // can travel, used to find the next reachable ledge
        int tank = time;

        // Iterator variable the index through the heights array
        uint i = (high + low)/2;

        // Using the divide and conquer strategy, continue moving the end points
        // until the low endpoint is higher than the high endpoint
        while (low < high) {
            mid = (high + low)/2;

            // If the next ledge is not reachable
            if (time * 2 < heights[mid + 1]) {
                // Move the low endpoint up since we couldn't reach
                // the next ledge
                low = mid + 1;

                // If there are no more ledges that can be tested, the we must
                // set burst to the difference of the next ledge and the
                // current ledge
                if (low == high && burst == UINT_MAX) {
                    burst = heights[mid + 1] - heights[mid];
                }
            } else {
                // The final ledge has been reached
                if (i == length - 1) {
                    // The final ledge cannot be reached in less time than the
                    // limit, thus we must move the lower endpoint up and
                    // reset all the variables
                    if (time > limit) {
                        low = mid + 1;
                        i = (high + low)/2;
                        mid = (high + low)/2;
                        time = heights[mid];
                        tank = time;
                    } else {
                        // A new minimum burst has been found
                        if (heights[mid] < burst) {
                            burst = heights[mid];
                        }
                        // Move the high endpoint to mid in order to find
                        // if there is a smaller burst value possible
                        high = mid;
                        i = (high + low)/2;
                        mid = (high + low)/2;
                        time = heights[mid];
                        tank = time;
                    }
                } else {
                    // Remove to the next ledge
                    tank -= (heights[i + 1] - heights[i]);
                    // If the next ledge cannot be reached, we rest at
                    // the ledge below it, add the time needed to climb
                    // to the ledge and time to rest, reset tank
                    if (tank < 0) {
                        time += (heights[i] - heights[mid]);
                        time += rest;
                        tank = heights[mid];
                    // The next ledge can be reached, increment i in order
                    // to check the next ledge
                    } else {
                        i += 1;
                    }
                }
            }
        }
    }
    return burst;
}

int main() {
    uint length, rest, limit;
    cin >> length;
    cin >> rest;
    cin >> limit;

    uint* heights = new uint[length];

    for (uint i = 0; i < length; i++) {
        cin >> heights[i];
    }

    cout << climbing(heights, length, rest, limit) << endl;
}
