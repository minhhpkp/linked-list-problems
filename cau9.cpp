Node* insertTail(Node* head, int value) {
    Node *newNode = new Node{value, nullptr};
    
    if (head == nullptr) {
        return newNode;
    }
    
    for (auto it = head; it != nullptr; it = it->next) {
        if (it->next == nullptr) {
            it->next = newNode;
            break;
        }
    }
    return head;
}
