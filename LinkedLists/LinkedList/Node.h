/*
 * File: Node.h
 */

#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node {

public:
    /*
     * Constructor
     */
    Node() : link(nullptr), data(-1) {}

    /*
     * Parameterized Constructor
     */
    Node(int param) : link(nullptr), data(param) {}

private:
    Node* link;
    int data;

    // declare Node a friend of LinkedList
    friend class LinkedList;

};

#endif