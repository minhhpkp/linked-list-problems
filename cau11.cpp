Node* deleteSingle(Node* head) {
    int current_value = head->value, number_of_occurences = 0;
    for (Node *it = head, *prv = nullptr; it != nullptr; ) {
        ++number_of_occurences;
        
        if (it->next == nullptr || it->next->value != current_value) {
            if (number_of_occurences == 1) {
                if (it == head) {
                    head = head->next;
                    delete it;
                    it = head;                
                }
                else {
                    prv->next = it->next;
                    delete it;
                    it = prv->next;
                }
            }
            else {
                prv = it;
                it = it->next;
            }
            if (it != nullptr) {
                current_value = it->value;
            }
            number_of_occurences = 0;
        }
        else {
            prv = it;
            it = it->next;
        }
    }
    
    return head;
}
