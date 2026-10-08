#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
}

DoublyLinkedList::~DoublyLinkedList()
{
    while (head != nullptr)
    {
        DNode* victim = head;
        head = head->next;
        delete victim;
    }
    tail = nullptr;
}

void DoublyLinkedList::insertAtFront(int value)
{
    DNode* newNode = new DNode;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = head;

    if (head == nullptr)
        tail = newNode;
    else
        head->prev = newNode;

    head = newNode;
}

void DoublyLinkedList::insertAtEnd(int value)
{
    DNode* newNode = new DNode;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = tail;

    if (tail == nullptr)
        head = newNode;
    else
        tail->next = newNode;

    tail = newNode;
}

void DoublyLinkedList::displayForward() const
{
    cout << "Forward:  ";
    for (DNode* cur = head; cur != nullptr; cur = cur->next)
        cout << cur->data << " <-> ";
    cout << "NULL" << endl;
}

void DoublyLinkedList::displayBackward() const
{
    cout << "Backward: ";
    for (DNode* cur = tail; cur != nullptr; cur = cur->prev)
        cout << cur->data << " <-> ";
    cout << "NULL" << endl;
}

bool DoublyLinkedList::deleteValue(int value)
{
    DNode* cur = head;
    while (cur != nullptr && cur->data != value)
        cur = cur->next;

    if (cur == nullptr)
        return false;

    if (cur->prev == nullptr)
        head = cur->next;
    else
        cur->prev->next = cur->next;

    if (cur->next == nullptr)
        tail = cur->prev;
    else
        cur->next->prev = cur->prev;

    delete cur;
    return true;
}
