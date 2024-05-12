#include "LinkedList.h"
using namespace std;
// Node constructor
Node::Node(int value) : value(value), next(nullptr) {}

// Node destructor
Node::~Node() {}

// LinkedList constructor
LinkedList::LinkedList(int value) : head(nullptr), tail(nullptr), length(0) {
    appendList(value);
}

// LinkedList destructor
LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Method to append a new node with the given value to the end of the list
void LinkedList::appendList(int value) {
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
void LinkedList::printList() {
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
bool LinkedList::isEmpty() const {
    return head == nullptr;
}

// Method to delete the last node in the list
void LinkedList::deleteLastNode() {
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
void LinkedList::addFirstNode(int value) {
    Node* node = new Node(value);
    if (isEmpty()) {
        tail = node;
    }
    node->next = head;
    head = node;
    length++;
}

// Method to delete the first node in the list
void LinkedList::deleteFirst() {
    if (!isEmpty()) {
        Node* temp = head;
        head = head->next;
        delete temp;
        length--;
        cout << "First node deleted." << endl;
    }
}

// Method to get the value of a node at a specific index
void LinkedList::getNode(int index) {
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
void LinkedList::changeNodeValue(int index, int newValue) {
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

// Method to insert a new node at the specified index with the given value
void LinkedList::insertNode(int index, int value) {
    if (index < 0 || index > length) {
        cout << "Invalid index." << endl;
        return;
    }
    else if (index == 0) {
        addFirstNode(value);
    }
    else if (index == length) {
        appendList(value);
    }
    else {
        Node* node = new Node(value);
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
        length++;
    }
}

// Method to delete a node at the specified index
void LinkedList::deleteNode(int index) {
    if (index < 0 || index >= length) {
        cout << "Invalid index." << endl;
        return;
    }
    else if (index == 0) {
        deleteFirst();
    }
    else if (index == length - 1) {
        deleteLastNode();
    }
    else {
        Node* current = head;
        Node* previous = nullptr;
        for (int i = 0; i < index; i++) {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        delete current;
        length--;
    }
}
#include "LinkedList.h"

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

    // Add new node to specified index
    myList.insertNode(3, 37);

    // Print after adding nodes to the index
    myList.printList();

    // Delete node in specified index
    myList.deleteNode(2);

    myList.printList();

    return 0;
}

