void printLast(Node *head, int k) {
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

Node* reverse(Node *head) {
    if (head == nullptr) {
        return head;
    }
    
    auto prv = head, now = head->next;
    head->next = nullptr;
    while (now != nullptr) {
        auto tmp = now->next;
        now->next = prv;
        prv = now;
        now = tmp;
    }
    
    return prv;
}

void printReverse(Node* head, int k) {
    head = reverse(head);
    
    printLast(head, k);
    
    reverse(head);
}
