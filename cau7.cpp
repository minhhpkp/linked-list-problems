#include <iostream>

Node::Node(int value): value(value), next(nullptr){}

LinkedList::LinkedList(): head(nullptr) {}

LinkedList::LinkedList(int a[], int n) {
    if (n > 0) {
        head = new Node(a[0]);
        auto it = head;
        for (int i = 1; i < n; ++i) {
            it->next = new Node(a[i]);
            it = it->next;
        }
    }
}

void LinkedList::insertHead(int value) {
    Node *newHead = new Node(value);
    newHead->next = head;
    head = newHead;
}

void LinkedList::print() {
    for (auto i = head; i != nullptr; i = i->next) {
        std::cout << i->value << ' ';
    }
}
