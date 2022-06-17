#include <iostream>
void printLast(Node* head, int k) {
    int size = 0, i = 0;
    for (auto it = head; it != nullptr; it = it->next) {
        size++;
    }
    
    for (auto it = head; it != nullptr; it = it->next, ++i) {
        if (i >= size - k) {
            std::cout << it->value << ' ';
        }
    }
}
