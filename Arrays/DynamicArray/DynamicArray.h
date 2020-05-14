/*
 * File: DynamicArray.h
 *
 * Pros of Dynamic Array
 *      Array access runs in constant time
 *
 * Cons of Dynamic Array
 *      Resizing the array runs in O(n) time
 *      May need to resize the array frequently
 *      Removing an element from the array requires copying the whole array and shifting parts of it
 *      Inserting an element into the array requires copying the whole array and shifting parts of it
 */

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

class DynamicArray {

public:
    /*
     * Constructor
     */
    DynamicArray();

    /*
     * Push
     */
    void Push(int data);

    /*
     * Push
     */
    void Push(int data, int idx);

    /*
     * Pop
     */
    int Pop();

    /*
     * Get
     */
    int Get(int idx);

    /*
     * Size
     */
    int Size();

    /*
     * Capacity
     */
    int GetCapacity();

    /*
     * Print
     */
    void Print();

private:

    /*
     * int CurrentSize
     *      Variable defines the number of elements currently in the array
     */
    int currentSize;

    /*
     * int capacity
     *      Variable defines the total number of elements the array can possibly store
     */
    int capacity;

    /*
     * int* container
     *      Array used as the primary data structure
     */
    int* container;

};

#endif //DYNAMICARRAY_H
