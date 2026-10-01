#pragma once
#include "Node.h"

class LinkedList {
private:
	Node* head;		// points to first node

public:
	LinkedList();	// constructor, creates empty list
	~LinkedList();	// destructor, deletes all nodes

	void insertAtFront(int value);	// prototypes only, no bodies here
	void display() const;
	bool isEmpty() const;
};