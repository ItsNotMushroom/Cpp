#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "list.h"
#include <iostream>

struct Node {
    int value;
    Node* next;
    Node(int val, Node* nxt = nullptr) : value(val), next(nxt) {}
};

class LinkedList : public List {
private:
    Node* head = nullptr;
    Node* LocateNode(int index) const;
    void AddToFront();
    void AddToTail();
    void AddAtIndex();
    void RemoveFromFront();
    void RemoveFromTail();
    void RemoveAtIndex();
    void SwapElements();
    void PrintList() const;
    void FreeList();
public:
    ~LinkedList();
    void PerformAction(int action) override;
};

#endif
