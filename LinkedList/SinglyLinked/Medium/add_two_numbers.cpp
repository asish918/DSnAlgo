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

    else{
        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = new_node;
        return head;
    }
}

Node* addTwoLists(Node* l1, Node* l2){
    Node* dummy = new Node(-1);
    Node* temp = dummy;

    int carry = 0;

    while(l1 != NULL || l2 != NULL || carry){
        int sum = 0;

        if(l1 != NULL){
            sum+=l1->data;
            l1 = l1->next;
        }

        if(l2 != NULL){
            sum+=l2->data;
            l2 = l2->next;
        }

        sum+=carry;
        carry = sum / 10;
        Node* new_node = new Node(sum % 10);
        temp->next = new_node;
        temp = temp->next;
    }

    return dummy->next;
}

void printList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    head1 = insert(head1, 2);
    head1 = insert(head1, 4);
    head1 = insert(head1, 3);

    head2 = insert(head2, 5);
    head2 = insert(head2, 6);
    head2 = insert(head2, 4);

    Node* head3 = addTwoLists(head1, head2);

    printList(head3);

    return 0;
}
