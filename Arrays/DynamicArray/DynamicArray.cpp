/*
 * File: DynamicArray.cpp
 */

#include "DynamicArray.h"
#include <iostream>

/*
 * Constructor
 */
DynamicArray::DynamicArray() {
    currentSize = 0;
    capacity = 1;
    container = new int[1];
}


/*
 * void Push (int data)
 *      Function: Add the element data to the end of the array
 *                Resize the array if current number of items equals capacity
 *      Run Time: O(n) - Resizing the array requires copying over n items
 */
void DynamicArray::Push(int data) {

    /*
     * Resize Process
     */
    // check to see if the current number of items in the array is at capacity
    if (currentSize == capacity) {
        // double the capacity
        capacity *= 2;

        // create new temporary array with the new doubled capacity
        int* tempArray = new int[capacity];

        // copy the data in the old array into the temp array
        for (int i = 0; i < currentSize; ++i) {
            tempArray[i] = container[i];
        }

        // delete container then set container to point to tempArray
        delete[] container;
        container = tempArray;
    }

    /*
     * Insertion Process
     */
    // add the data to position current size, increment current size
    container[currentSize] = data;
    currentSize++;

}


/* void Push (int data, int idx)
 *      Function: Add the element data to the position idx in the array
 *                Resize the array if the current number of items equals capacity
 *                Function will overwrite value currently in position idx
 *      Run Time: O(n) - Resizing the array requires copying over n items
 */
void DynamicArray::Push(int data, int idx) {

    // check that idx is not greater than capacity
    if (idx > capacity) {
        std::cout << "Index Out of Bounds, error in Push(int data, int idx)" << std::endl;
        return;
    }

    // if inserting at capacity, call push because the operation is the same
    if (idx == capacity) {
        Push(data);
    }

    // otherwise overwrite the value at the position idx
    else {
        container[idx] = data;
    }

}

/*
 * int Pop
 *      Function: Removes the last element from the list and returns it
 *      Run Time: O(1) - Get last elements and remove it, no resize operations
 */
int DynamicArray::Pop() {

    // create a temporary variable and store the last item in the array
    int temp = container[currentSize-1];

    // decrement current size, disallows access to the last element in the array
    currentSize--;

    // return the value stores
    return temp;

}

/*
 * int Get (int idx)
 *      Function: Returns the item at position idx in the array
 *      Run Time: O(1) - Accessing elements in array runs in constant time
 */
int DynamicArray::Get(int idx) {

    // error check for idx out of bounds
    if (idx >= currentSize) {
        std::cout << "Out of Bounds, error in Get(int idx) ";
        return 0;
    }

    // if idx is in bounds, return the value at position idx
    return container[idx];

}


/*
 * int Size
 *      Function: Returns the total number of elements stored in the array
 *      Run Time: O(1) - one operation, return private data member
 */
int DynamicArray::Size() {

    return currentSize;

}

/*
 * int GetCapacity
 *      Function: Returns the total number of elements that can be stored in the array
 *      Run Time: O(1) - only returns private data member
 */
int DynamicArray::GetCapacity() {

    return capacity;

}


/*
 * void Print
 *      Function: Prints the elements in the array to the screen
 *      Run Time: O(n) - output all n values in the array
 */
void DynamicArray::Print() {

    std::cout << "[ ";

    // iterate through all values in the array
    for (int i = 0; i < currentSize; ++i) {
        // check if its the last element in the array, unique cout
        if (i == currentSize - 1) {
            std::cout << container[i] << " ]" << std::endl;
        }

        // cout everything else the same
        else {
            std::cout << container[i] << ", ";
        }
    }

}

