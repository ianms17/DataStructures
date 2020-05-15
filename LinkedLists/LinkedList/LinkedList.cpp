/*
 * File: LinkedList.cpp
 */
#include "LinkedList.h"
#include "Node.h"
#include <iostream>

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
