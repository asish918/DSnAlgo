//Only functions mentioned
//Will not work out of the box


Node* mergeLists(struct Node* head1, struct Node* head2) {
    if(!head1) return head2;
    if(!head2) return head1;
    
    if(head1->data > head2->data) {
        Node* swap = head1;
        head1 = head2;
        head2 = swap;
    }
    
    Node* res = head1;
    while(head1 && head2) {
        Node* temp = NULL;
        while(head1 && head1->data <= head2->data) {
            temp = head1;
            head1 = head1->bottom;
        }
        
        temp->bottom = head2;
        
        Node* swap = head1;
        head1 = head2;
        head2 = swap;
    }
    
    return res;
}

Node *flatten(Node *root)
{
   // Your code here
  Node* h1 = root;
  Node* h2 = root->next;
  while(h2) {
      h1 = mergeLists(h1, h2);
      h2 = h2->next;
  }
   
   return h1;
}
