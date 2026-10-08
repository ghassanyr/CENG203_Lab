#pragma once
#include <Node.h>

class LinkedList {
private:
	Node* head;

public:
	LinkedList();
	~LinkedList();

	// WEEK 2
	void insertAtFront(int value);
	void display() const;
	bool isEmpty() const;

	// WEEK 3
	void insertAtEnd(int value);
	int length() const;
	void createFromArray(const int arr[], int n);
	int sparch(int value) const;
	int update(int oldValue, int newValue);
	bool insertAt(int index, int value);
	bool deleteValue(int value);
	void merge(LinkedList& other);
};