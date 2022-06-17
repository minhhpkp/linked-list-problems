// Cau 1 

void append(Node *a, Node *b) {
    b->next = a->next;
    a->next = b;
}

Node* convert(Node* head) {
    int n = 0;
    for (auto it = head; it != nullptr; it = it->next) {
        n++;
    }
    n /= 2;
    
    int i = -n + 1;
    for (auto b = head, a = head, prb = head; a != nullptr; b = b->next, ++i) {
        if (i == 0) {
            prb = b;
        }
        else if (i >= 1) {
            prb->next = b->next;      
            append(a, b);
            a = a->next->next;
            b = prb;
        }  
    }
    
    return head;
}
