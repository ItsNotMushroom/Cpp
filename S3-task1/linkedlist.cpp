#include "linkedlist.h"

LinkedList::~LinkedList() {
    FreeList();
}

void LinkedList::FreeList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

Node* LinkedList::LocateNode(int index) const {
    Node* current = head;
    while (current && index--) 
        current = current->next;
    return current;
}

void LinkedList::AddToFront() {
    int value;
    std::cout << "Enter value: ";
    std::cin >> value;
    head = new Node(value, head);
}

void LinkedList::AddToTail() {
    int value;
    std::cout << "Enter value: ";
    std::cin >> value;
    if (!head) 
        return AddToFront();
    Node* tail = head;
    while (tail->next) 
        tail = tail->next;
    tail->next = new Node(value);
}

void LinkedList::AddAtIndex() {
    int value, index;
    std::cout << "Enter index and value: ";
    std::cin >> index >> value;
    if (index == 0) 
        return AddToFront();
    Node* prev = LocateNode(index - 1);
    if (prev) 
        prev->next = new Node(value, prev->next);
    else 
        std::cout << "Invalid index.\n";
}

void LinkedList::RemoveFromFront() {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void LinkedList::RemoveFromTail() {
    if (!head) return;
    if (!head->next) 
        return RemoveFromFront();
    Node* prev = head;
    while (prev->next->next) 
        prev = prev->next;
    delete prev->next;
    prev->next = nullptr;
}

void LinkedList::RemoveAtIndex() {
    int index;
    std::cout << "Enter index: ";
    std::cin >> index;
    if (index == 0) 
        return RemoveFromFront();
    Node* prev = LocateNode(index - 1);
    if (prev && prev->next) {
        Node* temp = prev->next;
        prev->next = temp->next;
        delete temp;
    } else {
        std::cout << "Invalid index.\n";
    }
}

void LinkedList::SwapElements() {
    int i, j;
    std::cout << "Enter two indices: ";
    std::cin >> i >> j;
    if (i == j) return;
    Node* node1 = LocateNode(i);
    Node* node2 = LocateNode(j);
    if (node1 && node2) 
        std::swap(node1->value, node2->value);
    else 
        std::cout << "Invalid indices.\n";
}

void LinkedList::PrintList() const {
    Node* current = head;
    while (current) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void LinkedList::PerformAction(int action) {
    switch (action) {
        case 2: PrintList(); break;
        case 3: AddToFront(); break;
        case 4: AddToTail(); break;
        case 5: AddAtIndex(); break;
        case 6: RemoveFromFront(); break;
        case 7: RemoveFromTail(); break;
        case 8: RemoveAtIndex(); break;
        case 9: SwapElements(); break;
        default: std::cout << "Invalid action.\n"; break;
    }
}
