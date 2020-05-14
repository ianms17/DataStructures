/*
 * File: Driver.cpp
 */

#include "DynamicArray.h"
#include <iostream>
#include <stdlib.h>
#include <chrono>
using namespace std;

int main() {

    /*
     * Test Push(int data)
     */
    // create a DynamicArray
    DynamicArray da;

    // add elements to the array
    da.Push(6);
    da.Push(19);
    da.Push(12);
    da.Push(101);
    da.Push(61);
    da.Push(1114);

    // print that array
    cout << "Testing Push (int data)" << endl;
    da.Print();
    cout << endl;

    /*
     * Test Push(int data, int idx)
     */
    // should overwrite 101
    da.Push(-1, 3);
    cout << "Testing Push (int data, int idx)" << endl;
    da.Print();

    // push at out of bounds position, should print error message
    da.Push(-1, 10000);
    cout << endl;

    /*
     * Test Get
     */
    cout << "Testing Get" << endl;
    cout << "Element at Postion 5: " << da.Get(5) << endl;
    cout << da.Get(10000) << endl << endl;

    /*
     * Test Pop and Size
     */
    cout << "Testing Pop and Size" << endl;
    cout << "Array Size: " << da.Size() << endl;
    cout << "Last Element, " << da.Pop() << ", Removed" << endl;
    cout << "Array Size: " << da.Size() << endl << endl;

    /*
     * Test Running Time for very large values
     */
    DynamicArray largeArray;

    cout << "Test for Large Number of Inputs " << endl;
    cout << "Loop Timer" << endl;
    auto start = chrono::high_resolution_clock::now();
    // push 1,000,000 random values into the array
    for (int i = 0; i < 1000000; ++i) {
        int val = rand() % 1000;
        largeArray.Push(val);
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Loop Time: " << duration.count() << endl << endl;
}

