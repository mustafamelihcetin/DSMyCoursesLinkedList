#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

// Node class to represent individual nodes in the linked list
class Node
{
public:
    int value; // Value stored in the node
    Node* next; // Pointer to the next node

    // Constructor to initialize the node with a value
    Node(int value);

    // Destructor
    ~Node();
};

// LinkedList class to manage the linked list operations
class LinkedList {
private:
    Node* head; // Pointer to the first node in the list
    Node* tail; // Pointer to the last node in the list
    int length; // Length of the list

public:
    // Constructor to create a new linked list with an initial value
    LinkedList(int value);

    // Destructor to delete all nodes in the list
    ~LinkedList();

    // Method to append a new node with the given value to the end of the list
    void appendList(int value);

    // Method to print all values in the list
    void printList();

    // Method to check if the list is empty
    bool isEmpty() const;

    // Method to delete the last node in the list
    void deleteLastNode();

    // Method to add a new node at the beginning of the list
    void addFirstNode(int value);

    // Method to delete the first node in the list
    void deleteFirst();

    // Method to get the value of a node at a specific index
    void getNode(int index);

    // Method to change the value of a node at a specific index
    void changeNodeValue(int index, int newValue);

    // Method to insert a new node at the specified index with the given value
    void insertNode(int index, int value);

    // Method to delete a node at the specified index
    void deleteNode(int index);
};

#endif
