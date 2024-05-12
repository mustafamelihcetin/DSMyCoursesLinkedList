#include <iostream>
using namespace std;

// Node class to represent individual nodes in the linked list
class Node
{
public:
    int value; // Value stored in the node
    Node* next; // Pointer to the next node

    // Constructor to initialize the node with a value
    Node(int value) : value(value), next(nullptr) {}
};

// LinkedList class to manage the linked list operations
class LinkedList {
private:
    Node* head; // Pointer to the first node in the list
    Node* tail; // Pointer to the last node in the list
    int length; // Length of the list

public:
    // Constructor to create a new linked list with an initial value
    LinkedList(int value) : head(nullptr), tail(nullptr), length(0) {
        appendList(value);
    }

    // Destructor to delete all nodes in the list
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Method to append a new node with the given value to the end of the list
    void appendList(int value) {
        Node* node = new Node(value);
        if (isEmpty()) {
            head = node;
        }
        else {
            tail->next = node;
        }
        tail = node;
        length++;
    }

    // Method to print all values in the list
    void printList() {
        Node* current = head;
        while (current != nullptr) {
            if (current->next == tail->next) {
                cout << current->value << endl;
                return;
            }  
            else {
                cout << current->value << "-->";
                current = current->next;
            }            
        }
        cout << endl;
    }

    // Method to check if the list is empty
    bool isEmpty() const {
        return head == nullptr;
    }

    // Method to delete the last node in the list
    void deleteLastNode() {
        if (!isEmpty()) {
            Node* current = head;
            Node* previous = nullptr;
            while (current->next != nullptr) {
                previous = current;
                current = current->next;
            }
            if (previous != nullptr) {
                previous->next = nullptr;
                tail = previous;
            }
            else {
                head = nullptr;
                tail = nullptr;
            }
            delete current;
            length--;
            cout << "Last node deleted." << endl;
        }
    }

    // Method to add a new node at the beginning of the list
    void addFirstNode(int value) {
        Node* node = new Node(value);
        if (isEmpty()) {
            tail = node;
        }
        node->next = head;
        head = node;
        length++;
    }

    // Method to delete the first node in the list
    void deleteFirst() {
        if (!isEmpty()) {
            Node* temp = head;
            head = head->next;
            delete temp;
            length--;
            cout << "First node deleted." << endl;
        }
    }

    // Method to get the value of a node at a specific index
    void getNode(int index) {
        if (index >= 0 && index < length) {
            Node* current = head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            cout << "Value at index " << index << ": " << current->value << endl;
        }
        else {
            cout << "Invalid index." << endl;
        }
    }

    // Method to change the value of a node at a specific index
    void changeNodeValue(int index, int newValue) {
        if (index >= 0 && index < length) {
            Node* current = head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            current->value = newValue;
            cout << "Value at index " << index << " changed to " << newValue << endl;
        }
        else {
            cout << "Invalid index." << endl;
        }
    }
};

int main()
{
    // Create a new linked list with an initial value of 12
    LinkedList myList(12);

    // Append additional values to the list
    myList.appendList(5);
    myList.appendList(24);
    myList.appendList(8);
    myList.appendList(7);

    // Print the entire list
    myList.printList();

    // Delete the last node from the list
    myList.deleteLastNode();

    // Print the list after deletion
    myList.printList();

    // Add a new node to the beginning of the list
    myList.addFirstNode(10);

    // Print the list after adding a node at the beginning
    myList.printList();

    // Delete the first node from the list
    myList.deleteFirst();

    // Print the list after deleting the first node
    myList.printList();

    // Get the value of a node at index 0
    myList.getNode(0);

    // Change the value of a node at index 2
    myList.changeNodeValue(2, 40);

    // Print the final list after all operations
    myList.printList();

    return 0;
}
