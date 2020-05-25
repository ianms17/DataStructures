/*
 * File: LinkedList.cpp
 */
#include "LinkedList.h"
#include "Node.h"
#include <iostream>
#include <stdexcept>

using namespace std;

///// Public Functions /////

/*
 * Function: Constructor
 */
LinkedList::LinkedList() : HEAD(nullptr), TAIL(nullptr), size(0) {}

/*
 * Function: Destructor
 */
LinkedList::~LinkedList() {

    Node* cursor = HEAD;
    Node* previous = HEAD;

    while (cursor->link != nullptr) {
        // set previous to cursor for deletion
        previous = cursor;

        // set cursor to the next node in the list
        cursor = cursor->link;

        // set previous link to null and delete it
        previous->link = nullptr;
        delete previous;
    }

    HEAD = nullptr;
    TAIL = nullptr;
    size = 0;

}

/*
 * GetNode
 */
Node* LinkedList::GetNode(int idx) {

    // check if idx is out of bounds
    if (idx > size) {
        throw underflow_error("Index out of Bounds");
    }
    // check if idx is first element, call getHead
    if (idx == 0) {
        return GetHead();
    }
    // check if idx is last element, call getTail
    if (idx == size) {
        return GetTail();
    }

    // if not out of bounds, first, or last, then its in the middle
    int i = 0;
    Node* cursor = HEAD;
    while (i < idx) {
        // cursor equals the next node after to cursor
        cursor = cursor->link;
        i++;
    }
    return cursor;

}

/*
 * Function: Insert
 */
void LinkedList::Insert(int data, int idx) {

    // check out of bounds
    if (idx > size) {
        throw underflow_error("Index out of Bounds");
    }

    // idx is 0, call insert front
    if (idx == 0) {
        InsertFront(data);
        size++;
        return;
    }

    // idx is size, call insert back
    if (idx == size) {
        InsertBack(data);
        size++;
        return;
    }

    /*
     * otherwise inserting in middle
     */

    // create new insert node containing data passed in and set cursor to head
    Node* insert = new Node(data);
    Node* cursor = HEAD;

    // traverse to element idx in the list
    int i = 0;
    while (i < idx) {
        cursor = cursor->link;
        i++;
    }

    // point inserts link to cursors link, then cursors link to insert
    insert = cursor->link;
    cursor->link = insert;
    size++;

}

/*
 * Function: Remove
 */
void LinkedList::Remove(int idx) {

    // check that idx is in bounds
    if (idx > size) {
        throw underflow_error("Index out of Bounds");
    }

    // idx is 0, remove front
    if (idx == 0) {
        RemoveFront();
        size--;
        return;
    }

    // idx is size, remove back
    if (idx == size) {
        RemoveBack();
        size--;
        return;
    }

    /*
     * otherwise remove from middle
     */
    // create a cursor and previous node
    Node* cursor = HEAD;
    Node* previous = HEAD;

    // traverse cursor to removal node and previous to the element before cursor
    int i = 0;
    while (i < idx) {
        previous = cursor;
        cursor = cursor->link;
        i++;
    }

    // set previous link to cursors next link, set cursor link to null, delete cursor
    previous->link = cursor->link;
    cursor->link = nullptr;
    delete cursor;
    size--;

}


///// Private Helper Functions /////

/*
 * Function: InsertFront
 */
void LinkedList::InsertFront(int data) {

    // create a new node to insert into the list
    Node* insert = new Node(data);

    // point the insert node to the head node, set head to the insert
    insert->link = HEAD;
    HEAD = insert;

    // delete insert
    delete insert;

}


/*
 * Function: InsertBack
 */
void LinkedList::InsertBack(int data) {

    // create new insert node and point tails next to the new node
    Node* insert = new Node(data);
    TAIL->link = insert;

    // set tail to the inserted node and set inserts link to null
    TAIL = insert;
    insert->link = nullptr;

    // delete insert
    delete insert;

}


/*
 * Function: RemoveFront
 */
void LinkedList::RemoveFront() {

    // create a new cursor node and point it to head
    Node* cursor = HEAD;

    // reset head to heads link
    HEAD = HEAD->link;

    // set cursors link to NULL and delete it
    cursor->link = nullptr;
    delete cursor;

}


/*
 * Function: RemoveBack
 */
void LinkedList::RemoveBack() {

    // create a node pointer and set it to head
    Node* cursor = HEAD;
    Node* remove = TAIL;

    // traverse to node pointing to tail
    while (cursor->link != TAIL) {
        cursor = cursor->link;
    }

    // set tail to cursor and set cursors link to null
    TAIL = cursor;
    cursor->link = nullptr;

    // delete remove which was set to old tail
    delete remove;

}
