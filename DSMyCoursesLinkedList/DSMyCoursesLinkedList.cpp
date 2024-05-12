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
		cout << "Length of the list: " << this->length << endl;
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
	void deleteLastNode() {
		if (length == 0)
			return;
		Node* tmp1 = head;
		Node* tmp2 = head;
		while (tmp1->next) {
			tmp2 = tmp1;
			tmp1 = tmp1->next;
		}
		tail = tmp2;
		tail->next = NULL;
		length--;

		cout << "Last node is deleted." << endl;
		if (length == 0) {
			head = NULL;
			tail = NULL;
		}
		delete tmp1;
	}
	void AddFirstNode(int value) {
		Node* node = new Node(value);
		if (length == 0) {
			head = node;
			tail = node;
		}
		else {
			node->next = head;
			head = node;
		}
		length++;
	}
	void DeleteFirst() {
		if (length == 0) {
			return;
		}
		Node* temp = head;
		if (length == 1) {
			head = NULL;
			tail = NULL;
		}
		else {
			head = head->next;
		}
		delete temp;
		length--;
	}

	void GetNode(int index) {
		//Boundary condition check
		if (index < 0 || index >= length) {
			return;
		}
		Node* tmp1 = head;
		Node* tmp2 = head;
		int count = 0;
		while (tmp1->next) {
			if (count == index)
			{
				cout << index << ". node is " << tmp1->value;
			}
			else {

				tmp2 = tmp1;
				tmp1 = tmp1->next;
			}

			count++;
		}
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
	LinkedList1->printTail(); cout << endl;

	//Delete the last node
	LinkedList1->deleteLastNode(); cout << endl;

	// Print the entire list
	LinkedList1->printList(), cout << endl;;

	//Add a new node to the head of the List
	LinkedList1->AddFirstNode(10);
	LinkedList1->printList(), cout << endl;;

	// Delete first node from the list
	LinkedList1->DeleteFirst();
	LinkedList1->printList(), cout << endl;;

	LinkedList1->GetNode(0), cout << endl;

	// Delete the linked list to free memory
	delete LinkedList1;


	return 0;
}
