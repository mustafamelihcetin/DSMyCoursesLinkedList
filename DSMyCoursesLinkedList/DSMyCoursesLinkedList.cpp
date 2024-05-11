#include <iostream>
using namespace std;

class Node
{
public:
    int value; // Value stored in the node
    Node* next; // Pointer to the next node

    // Constructor to initialize the node with a value
    Node(int value) {
        this->value = value;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head; // Pointer to the first node in the list
    Node* tail; // Pointer to the last node in the list
    int length; // Length of the list

public:
    // Constructor to create a new linked list with an initial value
    LinkedList(int value) {
        Node* node = new Node(value);
        head = node;
        tail = node;
        length = 1;
    }

    // Destructor to delete all nodes in the list
    ~LinkedList() {
        cout << "Destructor is called" << endl;
        Node* tmp = head;
        while (head != NULL) {
            head = head->next;
            delete tmp;
            tmp = head;
        }
    }

    // Method to print the value of the first node (head) in the list
    void printHead() {
        if (head != NULL) {
            cout << "Head: " << head->value << endl;
        }
    }

    // Method to print the value of the last node (tail) in the list
    void printTail() {
        if (tail != NULL) {
            cout << "Tail: " << tail->value << endl;
        }
    }

    // Method to get the length of the list
    void getLength() {
        cout << "List Length: " << this->length << endl;
    }

    // Method to append a new node with the given value to the end of the list
    void appendList(int value) {
        Node* node = new Node(value);
        if (length == 0) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
        length++;
    }

    // Method to print all values in the list
    void printList() {
        Node* tmp = head;
        while (tmp != NULL) {
            cout << tmp->value << "--";
            tmp = tmp->next;
        }
        cout << endl;
    }
};

int main()
{
    // Create a new linked list with an initial value of 12
    LinkedList* LinkedList1 = new LinkedList(12);

    // Append additional values to the list
    LinkedList1->appendList(5);
    LinkedList1->appendList(24);
    LinkedList1->appendList(8);
    LinkedList1->appendList(7);

    // Print the entire list
    LinkedList1->printList();

    // Get and print the length of the list
    LinkedList1->getLength();

    // Print the value of the first node (head)
    LinkedList1->printHead();

    // Print the value of the last node (tail)
    LinkedList1->printTail();

    // Delete the linked list to free memory
    delete LinkedList1;

    return 0;
}
