#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};
Node* head = NULL;

Node* insert(Node* head, int value){
    Node* new_node = new Node(value);

    if(head == NULL)
        head = new_node;
    else{
        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = new_node;
        new_node->prev = temp;
    }

    return head;
}

Node* removeDuplicates(Node* head){
    Node* fast = head;
    Node* slow = head;

    while(fast != NULL){
        if(fast->data != slow->data){
            slow->next = fast;
            fast->prev = slow;
            slow = fast;
        }
        else
            fast = fast->next;
    }

    slow->next = NULL;

    return head;
}

void printList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    head = insert(head, 1);
    head = insert(head, 1);
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);

    head = removeDuplicates(head);

    printList(head);

    return 0;
}
