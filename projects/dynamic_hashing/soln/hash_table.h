#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_

#include "linked_list.h"
#include "dynarray.h"
#include <cassert>

template <typename T>
class HashTable {
public:
  // creates an empty hash table with the given number of buckets.
  // Set the default value to 10
  HashTable(unsigned int tableSize = 10);

  HashTable(const HashTable<T>& copy);
  ~HashTable();

  HashTable<T>& operator=(const HashTable<T>& rhs);

  // Check if the item already appears in the table.
  bool contains(const T& item) const;

  // Insert the item, do nothing if it is already in the table.
  // Returns true iff the insertion was successful (i.e. the item was not there).
  bool insert(const T& item);

  // Removes the item after checking, via assert, that the item was in the table.
  void remove(const T& item);

  // Returns the number of items in the hash table.
  unsigned int size() const;

  // Returns the number of buckets in the hash table.
  unsigned int getBucketCount() const;

  // Returns a dynamic array containing the items in the hash table
  // (in no particular order).
  DynamicArray<T> getItemsArray() const;

private:
  LinkedList<T> *table; // start of the array of linked lists (buckets)
  unsigned int numItems; // # of items in the table

  unsigned int tableSize; // # of buckets

  // Computes the hash table bucket that the item maps into
  // by calling it's .hash() method.
  unsigned int getBucket(const T& item) const;
};

template <typename T>
HashTable<T>::HashTable(unsigned int tableSize) {
  // make sure there is at least one bucket
  assert(tableSize > 0);

  // calls the constructor for each linked list
  // so each is initialized properly as an empty list
  table = new LinkedList<T>[tableSize];

  // we are not storing anything
  numItems = 0;
  this->tableSize = tableSize;
}

template <typename T>
HashTable<T>::HashTable(const HashTable<T>& copy) {
  table = NULL;

  *this = copy;
}


template <typename T>
HashTable<T>::~HashTable() {
  // this will call the destructor for the linked list in each bucket
  delete[] table;
}

template <typename T>
HashTable<T>& HashTable<T>::operator=(const HashTable<T>& rhs) {
  // it could be table == NULL (if calling this from the copy constructor)
  // so best to double-check before we delete the old table
  if (table != NULL) {
    delete[] table;
  }

  tableSize = rhs.tableSize;
  numItems = rhs.numItems;

  table = new LinkedList<T>[tableSize];

  for (int i = 0; i < tableSize; i++) {
    // uses the = operator for the linked lists, so we truly get
    // a copy of each list in the rhs
    table[i] = rhs.table[i];
  }

  return *this;
}

template <typename T>
bool HashTable<T>::contains(const T& item) const {
  unsigned int bucket = getBucket(item);

  return table[bucket].find(item) != NULL;
}


/* 
  Descirption: Insert the item into the hash table, do nothing if it is already in the table.

  Arguments: item (const T&): The item the user would like to insert into the hash table

  Returns: Returns true if the insertion was successful (i.e. the item was not there)
  and returns false if the item was already in there
*/
template <typename T>
bool HashTable<T>::insert(const T& item) {
  // if the item is here, return false
  if (contains(item)) {
    return false;
  }
  else {
    // otherwise, insert it into the front of the list
    // in this bucket and return true
    unsigned int bucket = getBucket(item);
    table[bucket].insertFront(item);
    ++numItems;

    // Check if the number of items exceeds the number of buckets, allocate a new array of 
    // buckets (each holding a linked list) that is twice the size of the current array of buckets
    // Then iterate through all items in the old hash table, recompute the bucket they should 
    // occupy in the new array of buckets, and add the item to the list in that new bucket.
    if (numItems > tableSize) {
      // New tablesize twice the size of the current size
      unsigned int newSize = (2 * tableSize);

      // Create a new hash table with the new size
      LinkedList<T> *newTable = new LinkedList<T>[newSize];

      // Get all current items in the hash table
      DynamicArray<T> items_array = getItemsArray();

      this->tableSize = newSize;

      // Insert all items from the items array into the new hash table
      // first by celculating the bucket for the item and then using the 
      // insertFront function to insert the item into the bucket
      for (unsigned int i = 0; i < numItems; i++) {
        unsigned int bucket = getBucket(items_array[i]);
        newTable[bucket].insertFront(items_array[i]);
      }
      // Must deallocate memory for the old table
      delete[] table;
      table = newTable;
    }
    return true;
  }
}

/* 
  Descirption: Removes the item after checking, via assert, that the item was in the table.

  Arguments: item (const T&): The item the user would like to remove from the hash table 

  Returns: None
*/
template <typename T>
void HashTable<T>::remove(const T& item) {
  unsigned int bucket = getBucket(item);

  ListNode<T>* link = table[bucket].find(item);

  // make sure the item was in the list
  assert(link != NULL);

  table[bucket].removeNode(link);

  --numItems;

  // Check if the number of items is less than 1/4 of the number of 
  // buckets and the number of buckets is greater than the default size of 10
  // Then allocate a new array of buckets of max (tablesize/2, 10
  // Iterate through all items in the old hash table, recompute the bucket they should occupy
  // in the new array of buckets, and add the item to the list in that new bucket
  if (numItems < (tableSize / 4) and tableSize > 10) {
    unsigned int newSize;
    if (tableSize / 2 > 10) {
      newSize = (tableSize / 2);
    } else {
      newSize = 10;
    }

    // Create a new hash table with the new size
    LinkedList<T> *newTable = new LinkedList<T>[newSize];

    // Get all current items in the hash table
    DynamicArray<T> items_array = getItemsArray();
    this->tableSize = newSize;

    // Insert all items from the items array into the new hash table
    // first by celculating the bucket for the item and then using the 
    // insertFront function to insert the item into the bucket
    for (unsigned int i = 0; i < numItems; i++) {
      unsigned int bucket = getBucket(items_array[i]);
      newTable[bucket].insertFront(items_array[i]);
    }
    // Must deallocate memory for the old table
    delete[] table;
    table = newTable;
    }
  }

template <typename T>
unsigned int HashTable<T>::size() const {
  return numItems;
}

template <typename T>
unsigned int HashTable<T>::getBucketCount() const {
  return tableSize;
}

template <typename T>
DynamicArray<T> HashTable<T>::getItemsArray() const {
  DynamicArray<T> array;

  // go through each bucket
  for (unsigned int i = 0; i < tableSize; i++) {
    // and crawl along the list in the bucket to add the items to the array
    ListNode<T>* node = table[i].getFirst();
    while (node != NULL) {
      array.pushBack(node->item);
      node = node->next;
    }
  }

  // returns a copy of the array because it is a local variable
  return array;
}


template <typename T>
unsigned int HashTable<T>::getBucket(const T& item) const {
  return item.hash() % tableSize;
}



#endif
