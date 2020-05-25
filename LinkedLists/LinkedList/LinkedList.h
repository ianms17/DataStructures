/*
 * File: LinkedList.h
 */

/*
 * Pros and Cons of Linked List
 *  Pros:
 *      Insertion into linked list will never need to resize the list
 *      Removal from linked list will never need to resize the list
 *  Cons:
 *      Getting an element from the list is O(n) time complexity
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"

class LinkedList {

public:
    /*
     * Constructor
     */
    LinkedList();

    /*
     * Destructor
     */
    ~LinkedList();

    /*
     * Insert
     */
    void Insert(int data, int idx);

    /*
     * Remove
     */
    void Remove(int idx);

    /*
     * GetNode
     */
    Node* GetNode(int idx);

    /*
     * GetHead
     */
    Node* GetHead() { return HEAD; }

    /*
     * GetTail
     */
    Node* GetTail() { return TAIL; }

    /*
     * GetSize
     */
    int GetSize() { return size; }

    /*
     * PrintList
     */
    void PrintList();

private:
    ///// Private Data Members /////
    Node* HEAD;
    Node* TAIL;
    int size;

    ///// Private Helper Functions /////
    void InsertFront(int data);
    void InsertBack(int data);
    void RemoveFront();
    void RemoveBack();

};

#endif
