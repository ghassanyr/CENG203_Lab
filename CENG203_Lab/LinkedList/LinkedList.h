#pragma once
#include "Node.h"

class LinkedList
{
private:
    Node* head;

public:
    LinkedList();
    ~LinkedList();

    // ---- Week 2 ----
    void insertAtFront(int value);
    void display() const;
    bool isEmpty() const;

    // ---- Week 3 ----
    void insertAtEnd(int value);
    int  length() const;
    void createFromArray(const int arr[], int n);
    int  search(int value) const;
    int  update(int oldValue, int newValue);
    bool insertAt(int index, int value);
    bool deleteValue(int value);
    void merge(LinkedList& other);

    // ---- Week 5: recursion ----
    void displayBackward() const;   // 4 3 2 1 - via printBackward
    void reverse();                 // in place - via reverseFrom

private:
    static void  printBackward(const Node* node);   // recursive helper
    static Node* reverseFrom(Node* node);           // returns new head
};
