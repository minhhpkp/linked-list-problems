Node* deleteNode(Node* head, int pos) {
    if (head == nullptr) {
        return head;
    }
    
    int i = 0;
    for (Node *it = head, *prv = nullptr; it != nullptr; it = it->next, ++i) {
        if (i == pos) {
            if (it == head) {
                head = head->next;
                delete it;
            }
            else {
                prv->next = it->next;
                delete it;
                it = prv;
            }
            break;
        }
        else if (i == pos - 1) {
            prv = it;
        }
    }
    
    return head;
}
