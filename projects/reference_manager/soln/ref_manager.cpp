#include "ref_manager.h"
#include <assert.h>

// Constructor
ReferenceManager::ReferenceManager() {
    numToDelete = 0;
    for (int i = 0; i < MAX_PTRS; i++) {
        pointers[i] = NULL;
    }
}

/* 
    Descirption: Destructor
    Goes through all pointers in the pointers array from the
    first index to the last index and calls reassignPointer() to reassign
    all pointers in the pointers array to NULL. First garbageCollect() is called
    to print and free all memory currently stored in garbage array. Then all remaining 
    strings in the order their reference counts dropped to 0 as their pointers were reassigned 
    to NULL. garbageCollect() is then called again to print each string 
    and free all memory from the pointers array that was added to the garbage array.
    All remaining strings after the first garbage collection are added to the garbage
    array in the order their reference counts dropped to 0 as their pointers were reassigned
    to NULL
*/
ReferenceManager::~ReferenceManager() {
    garbageCollect();
    for (int i = 0; i < MAX_PTRS; i++) {
        // Do not need to reassign a pointer to NULL if that pointer
        // is already a NULL pointer
        if (pointers[i] != NULL) {
            reassignPointer(i, NULL);
        }
    }
    garbageCollect();
}

/* 
    Descirption: Goes through all strings in the garbage array, prints each string and then
    frees the memory using the delete operator. The strings are printed in the order they
    were added to the garbage array. 

    Arguments: None

    Returns: None 
*/
void ReferenceManager::garbageCollect() {
    // iterates through all index in garbage array
    // until i > numToDelete
    for (int i = 0; i < numToDelete; i++) {
        const char* str = garbage[i];
        // print the string stored at each index
        cout << str << endl;
        // Delete the character array at each index
        delete[] garbage[i];
        // set each pointer to NULL after the memory has been freed
        garbage[i] = NULL;
    }
    // Must reset the counter since each character array was freed
    numToDelete = 0;
}

/* 
    Descirption: Makes the pointer at ptrIndex in the pointers array reference newAddr.
    In addition, the reference counts in the unordered map refCount are updated. 
    The reference count at the string previously stored at ptrIndex is decremented by 1.
    If the string's reference count drops to 0, this string is added to the garbage array
    to be deleted next time garbageCollect() is called. The reference count for the newAddr
    is incremented by 1 if it already exists in refCount or a new key-pair is created and set
    to 1.

    Arguments: ptrIndex (unsigned int): The index of the pointer the user would like
    to reassign
    newAddr (const char*): A character array the user would like the pointer at the ptrIndex
    in the pointer array to know point to. newAddr can also be NULL

    Returns: None 
*/
void ReferenceManager::reassignPointer(unsigned int ptrIndex, const char* newAddr) {
    // If the pointer at ptrIndex points to nothing, they we don't
    // need to decrement its reference count since it does not exist in refCount
    if (pointers[ptrIndex] == NULL) {
        pointers[ptrIndex] = newAddr;
        // If newAddr is already referenced by another pointer in the
        // pointers array then the reference count is incremented by 1
        if (refCount.find(newAddr) != refCount.end()) {
            refCount[newAddr]++;
        // Otherwise the string is new and a new key-value pair
        // is created and set to 1
        } else {
            refCount[newAddr] = 1;
        }
    // Else the pointer at ptrIndex in the pointers array is not NULL
    // thus it must already have a pointer there
    } else {
        // The reference count for the previous string is decremented
        refCount[pointers[ptrIndex]]--;
        // If the reference count drops to 0 the string is added to the
        // garbage array to be deleted next time garbageCollect() is called
        // The numToDelete counter is incremented
        if (refCount[pointers[ptrIndex]] == 0) {
            garbage[numToDelete] = pointers[ptrIndex];
            numToDelete++;
        }
        // The pointer at ptrIndex now references newAddr
        pointers[ptrIndex] = newAddr;
        // If newAddr is already referenced by another pointer
        // then the reference count is incremented by 1
        if (refCount.find(newAddr) != refCount.end()) {
            refCount[newAddr]++;
        // Otherwise the string is new and a new key-value pair
        // is created and set to 1
        } else {
            refCount[newAddr] = 1;
        }
    }
}

/* 
    Descirption: Allocates space for a string of size length using new. Reads in 
    a string of size length from standard input and stores it in the allocated space.
    Uses the method reassginPointer() to have the pointer at index ptrIndex reference
    the newly allocated string.

    Arguments: ptrIndex(unsigned int): The index of the pointer in the pointers  
    array that the user would like to reassigned this string to
    length (unsigned int): The size of the string that is being added

    Returns: None 
*/
void ReferenceManager::readString(unsigned int ptrIndex, unsigned int length) {
    // Must set the size of the character array to length + 1
    // to include space for the null terminating character
    char *char_arr = new char[length + 1];
    cin >> char_arr;
    reassignPointer(ptrIndex, char_arr);
}

const char* ReferenceManager::getPtr(unsigned int ptrIndex) {
  assert(ptrIndex < MAX_PTRS);
  return pointers[ptrIndex];
}
