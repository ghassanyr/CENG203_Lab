#pragma once
#include "DNode.h"

class DoublyLinkedList
{
private:
    DNode* head;                        // first node
    DNode* tail;                        // last node: makes insertAtEnd O(1)

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void insertAtFront(int value);
    void insertAtEnd(int value);
    void displayForward() const;
    void displayBackward() const;
    bool deleteValue(int value);
};
