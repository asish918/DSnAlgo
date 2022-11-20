#include<iostream>
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

void createIntersection(Node* &head1, Node* &head2){
    Node* dummy = NULL;
    dummy = insert(dummy, 8);
    dummy = insert(dummy, 4);
    dummy = insert(dummy, 5);

    Node* temp1 = head1;
    Node* temp2 = head2;

    while(temp1->next)
        temp1 = temp1->next;

    while(temp2->next)
        temp2 = temp2->next;

    temp1->next = dummy;
    temp2->next = dummy;
}

// Noob brute force
Node* find_intersection(Node* head1, Node* head2){
    Node* temp = head1;

    while(head2){
        head1 = temp;
        while(head1){
            if(head1 == head2)
                return head1;

            head1 = head1->next;
        }
        head2 = head2->next;
    }

    return NULL;
}

void printList(Node* head){
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    head1 = insert(head1, 4);
    head1 = insert(head1, 1);

    head2 = insert(head2, 5);
    head2 = insert(head2, 6);
    head2 = insert(head2, 1);

    createIntersection(head1, head2);

    printList(head1);
    printList(head2);

    Node* ans = find_intersection(head1, head2);

    if(ans)
        cout << ans->data << " " << endl;
    else
     cout << "NUMLL" << endl;

    return 0;
}
