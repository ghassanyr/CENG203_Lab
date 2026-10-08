#include "Labs.h"
#include "../LinkedList/Node.h"
#include "../LinkedList/LinkedList.h"
#include "../LinkedList/CircularList.h"
#include "../LinkedList/DoublyLinkedList.h"
#include <iostream>
using namespace std;

void runWeek03() {
	Node* n1 = nullptr;
	cout << "[Q1] n1 = " << n1 << "sizeof(n1)= " << sizeof(n1) << "sizeof(Node)= " << sizeof(Node) << endl;
	n1 = new Node();
	cout << "[Q1] after new: data = " << n1->data << "next= " << n1->next << endl;

	Node* n2 = new Node();
	Node* n3 = new Node();
	n1->data = 5; n2->data = 7; n3->data = 11;
	n1->next = n2; n2->next = n3; n3->next = nullptr;

	for (Node* cur = n1; cur!= nullptr; cur = cur->next) {
		cout << "[Q2] " << cur << " data = " << cur->data << " next = " << cur->next << endl;
	}
	delete n3; delete n2; delete n1;

	// Q2
	int arr[] = { 7,2,5,4 };
	LinkedList list;
	list.createFromArray(arr, 4);
	cout << "[Q2] "; list.display();
	cout << "[Q2] length = " << list.length() << endl;

	// Q3

}