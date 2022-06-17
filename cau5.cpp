// ...
void printLinkedList(SinglyLinkedListNode* head) {
    for (auto it = head; it != nullptr; it = it->next) {
        std::cout << it->data << '\n';
    }
}
// ...
