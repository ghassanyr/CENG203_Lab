#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList()
{
    head = nullptr;
}

LinkedList::~LinkedList()
{
    while (head != nullptr)
    {
        Node* victim = head;
        head = head->next;
        delete victim;
    }
}

void LinkedList::insertAtFront(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void LinkedList::display() const
{
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        cout << cur->data << " -> ";
    cout << "NULL" << endl;
}

bool LinkedList::isEmpty() const
{
    return head == nullptr;
}

// =============================== Week 3 ===============================

void LinkedList::insertAtEnd(int value)                     // Q2
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* cur = head;
    while (cur->next != nullptr)
        cur = cur->next;
    cur->next = newNode;
}

int LinkedList::length() const                              // Q2
{
    int count = 0;
    for (Node* cur = head; cur != nullptr; cur = cur->next)
        count++;
    return count;
}

void LinkedList::createFromArray(const int arr[], int n)    // Q2
{
    for (int i = 0; i < n; i++)
        insertAtEnd(arr[i]);
}

int LinkedList::search(int value) const                     // Q3
{
    int index = 0;
    for (Node* cur = head; cur != nullptr; cur = cur->next)
    {
        if (cur->data == value)
            return index;
        index++;
    }
    return -1;
}

int LinkedList::update(int oldValue, int newValue)          // Q4
{
    int changed = 0;
    for (Node* cur = head; cur != nullptr; cur = cur->next)
    {
        if (cur->data == oldValue)
        {
            cur->data = newValue;
            changed++;
        }
    }
    return changed;
}

bool LinkedList::insertAt(int index, int value)             // Q5
{
    if (index < 0 || index > length())
        return false;

    Node* newNode = new Node;
    newNode->data = value;

    if (index == 0)
    {
        newNode->next = head;
        head = newNode;
        return true;
    }

    Node* prev = head;
    for (int i = 0; i < index - 1; i++)
        prev = prev->next;

    newNode->next = prev->next;
    prev->next = newNode;
    return true;
}

bool LinkedList::deleteValue(int value)                     // Q6
{
    if (head == nullptr)
        return false;

    if (head->data == value)
    {
        Node* victim = head;
        head = head->next;
        delete victim;
        return true;
    }

    Node* prev = head;
    while (prev->next != nullptr && prev->next->data != value)
        prev = prev->next;

    if (prev->next == nullptr)
        return false;

    Node* victim = prev->next;
    prev->next = victim->next;
    delete victim;
    return true;
}

void LinkedList::merge(LinkedList& other)                   // Q7
{
    if (other.head == nullptr)
        return;

    if (head == nullptr)
    {
        head = other.head;
    }
    else
    {
        Node* cur = head;
        while (cur->next != nullptr)
            cur = cur->next;
        cur->next = other.head;
    }

    other.head = nullptr;
}

// =============================== Week 5 ===============================
void LinkedList::displayBackward() const
{
    printBackward(head);
    cout << endl;
}

void LinkedList::printBackward(const Node* node)
{
    if (node == nullptr)
        return;
    printBackward(node->next);
    cout << node->data << " ";
}

void LinkedList::reverse()
{
    head = reverseFrom(head);
}

Node* LinkedList::reverseFrom(Node* node)
{
    if (node == nullptr || node->next == nullptr)
        return node;
    Node* newHead = reverseFrom(node->next);
    node->next->next = node;
    node->next = nullptr;
    return newHead;
}
