void insert(Node* &head, Node* &end, Node *toinsert) {
    for (auto it = end; ; it = it->prev) {        
        // when *toinsert* < *head*, make *toinsert* the head of the list
        if (it == nullptr) {
            toinsert->next = head;
            head->prev = toinsert;

            toinsert->prev = nullptr;
            head = toinsert;
            break;
        }
        // this holds true when *it* is the first element from the end of the list that can precede toinsert
        // the last elements after *it* is larger than toinsert and have to go after toinsert
        else if (toinsert->getValue() >= it->getValue()) {
            Node *next = it->next;

            it->next = toinsert;
            toinsert->prev = it;

            toinsert->next = next;
            if (next != nullptr) next->prev = toinsert;

            if (it == end) {
                end = toinsert;
            }
            break;            
        }
    }
}

Node* sort(Node* head) {
    if (head == nullptr) {
        return head;
    }
    
    // *end* is the last element of first sorted elements
    for (auto end = head; end->next != nullptr;) {
        Node *toinsert = end->next;
        
        // temporarily remove toinsert out of the list
        end->next = toinsert->next;
        if (toinsert->next != nullptr) {
            toinsert->next->prev = end;
        }
        
        // reinsert toinsert into the list
        insert(head, end, toinsert);
    }

    return head;
}
