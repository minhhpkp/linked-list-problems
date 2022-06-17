void append(Node *a, Node *b) {
    b->next = a->next;
    a->next = b;
}

inline bool func_greater(int a, int b) {
    return a > b;
}
inline bool func_less(int a, int b) {
    return a < b;
}

Node* insert(Node* head, int value) {
    auto newNode = new Node{value, nullptr};
    if (head == nullptr) {
        return newNode;
    }
    
    if (head->next == nullptr) {
        if (value < head->value) {
            newNode->next = head;
            return newNode;
        }
        else {
            head->next = newNode;
            return head;
        }
    }
    
    auto comp = head->value > head->next->value ? &func_greater : &func_less;
    
    if (comp(newNode->value, head->value)) {
        newNode->next = head;
        head = newNode;
    }
    else {
        for (auto it = head; it != nullptr; it = it->next) {
            if (it->next == nullptr || comp(newNode->value, it->next->value)) {
                append(it, newNode);
                break;
            }
        }
    }
    
    return head;
}
