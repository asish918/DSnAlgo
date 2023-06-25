// Only function since question is tough to recreate

Node *copyList(Node *head)
    {
        //Write your code here
        Node* iter = head;
        Node* front = head;
        
        while(iter != NULL) {
            front = iter->next;
            iter->next = new Node(iter->data);
            iter->next->next = front;
            iter = front;
        }
        
        iter = head;
        while(iter != NULL) {
            if(iter->arb != NULL) {
                iter->next->arb = iter->arb->next;
            }
            
            iter = iter->next->next;
        }
        
        Node* ans = new Node(-1);
        Node* dummy = ans;
        iter = head;
        front = head;
        
        while(iter != NULL) {
            front = iter->next->next;
            dummy->next = iter->next;
            iter->next = front;
            dummy = dummy->next;
            iter = iter->next;
        }
        
        return ans->next;
    }
