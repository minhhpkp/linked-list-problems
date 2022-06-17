void rotate(Node* &head, int k) {
    if (k == 0) return;
    
    int i = 0;
    for (Node *it = head, *toinsert = nullptr, *last = nullptr; it != nullptr; ++i) {                
        if (i == k - 1) {
            last = it;
        }

        if (i == k) {
            last->next = nullptr;

            Node *tmp = it->next;

            it->next = head;
            toinsert = head = it;

            it = tmp;            
        }
        else if (i > k) {
            Node *tmp = it->next;

            // insert *it* into *toinsert*
            Node *tmp1 = toinsert->next;
            toinsert->next = it;
            it->next = tmp1;

            // update *toinsert*
            toinsert = it;
            
            it = tmp;
        }
        else {
            it = it->next;
        }
    }
}
