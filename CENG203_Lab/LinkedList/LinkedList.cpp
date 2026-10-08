#include <LinkedList.h>
#include <iostream>
using namespace std;

LinkedList::LinkedList() {
	head = nullptr;
}


// WEEK 3

void LinkedList::insertAtEnd(int value) {
	Node* node = new Node();
	node->data = value;
	node->next = nullptr;

	if (head == nullptr) {
		head = node;
		return;
	}

	Node* cur = head;
	while (cur->next != nullptr) {
		cur = cur->next;
	}
	cur->next = node;
}

int LinkedList::length() const {
	int count = 0;
	for (Node* cur = head; cur != nullptr; cur = cur->next) {
		++count;
	}
	return count;
}

void LinkedList::createFromArray(const int arr[], int n) const {
	// clear existing list
	Node* cur = head;
	while (cur != nullptr) {
		Node* tmp = cur;
		cur = cur->next;
		delete tmp;
	}
	head = nullptr;

	// append each array element
	for (int i = 0; i < n; ++i) {
		insertAtEnd(arr[i]);
	}
}

int LinkedList::search(int value) const {
	return -1;
}

int LinkedList::update(int oldValue, int newValue) {
	return 0;
}

bool LinkedList::insertAt(int index, int value) {
	return false;
}

bool LinkedList::deleteValue(int value) {
	return false;
}

void LinkedList::merge(LinkedList& other) {
	// TODO
}