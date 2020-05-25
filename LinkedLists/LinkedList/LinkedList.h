/*
 * File: LinkedList.h
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
