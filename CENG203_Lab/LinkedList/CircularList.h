#pragma once
#include "Node.h"

// Singly linked list whose last node points back to the first node
class CircularList
{
private:
    Node* head;

public:
    CircularList();
    ~CircularList();

    void append(int value);
    void display() const;
    int  length() const;
};
