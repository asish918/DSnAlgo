#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

Node* head1 = NULL;
Node* head2 = NULL;

Node* insert(Node* head, int value){
    Node* new_node = new Node(value);

    if(head == NULL){
        head = new_node;
        return head;
    }

    else {
        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = new_node;
        return head;
    }
}

Node* mergeTwoSorted(Node* head1, Node* head2){
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;
    if(head1->data > head2->data){
        Node* swap_temp = head1;
        head1 = head2;
        head2 = swap_temp;
    }

    Node* res = head1;

    while(head1 != NULL && head2 != NULL){
        Node* temp = NULL;
       while(head1 != NULL && head1->data <= head2->data){
           temp = head1;
           head1 = head1->next;
       }

       temp->next = head2;

       Node* swap_temp = head1;
       head1 = head2;
       head2 = swap_temp;
    }

    return res;
}

void printList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    head1 = insert(head1, 1);
    head1 = insert(head1, 3);
    head1 = insert(head1, 5);
    head1 = insert(head1, 7);
    head1 = insert(head1, 9);

    head2 = insert(head2, 2);
    head2 = insert(head2, 4);
    head2 = insert(head2, 6);
    head2 = insert(head2, 8);

    Node* head3 = mergeTwoSorted(head1, head2);

    printList(head3);

    return 0;
}
