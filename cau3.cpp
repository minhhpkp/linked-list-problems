#include <iostream>
void print(Node* head) {
    for (auto it = head; it != nullptr; it = it->next) {
        std::cout << it->value << ' ';
    }
}
