Node* deleteDuplicates(Node* head) {
    for (auto it1 = head; it1 != nullptr; it1 = it1->next) {
        for (auto it2 = it1->next, prv = it1; it2 != nullptr; it2 = it2->next) {
            if (it1->value == it2->value) {
                // it2 cannot be head
                prv->next = it2->next;
                delete it2;
                it2 = prv;
            }
            prv = it2;
        }
    }
    
    return head;
}
