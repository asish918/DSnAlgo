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

Node* head = NULL;

struct Node* insert(Node* head, int value){
    Node* new_node = new Node(value);

    if(head == NULL)
        head = new_node;
    else{
        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = new_node;
    }

    return head;
}

Node* rotateKNoob(Node* head, int k){

    for(int i = 0; i<k; i++){
        Node* temp = head;
        while(temp->next->next != NULL)
            temp = temp->next;

        temp->next->next = head;
        head = temp->next;
        temp->next = NULL;
    }

    return head;
}

Node* rotateKOptimal(Node* head, int k){
    int len = 1;
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        len++;
    }

    temp->next = head;
    k = len - k;

    while(k--) temp = temp->next;

    head = temp->next;
    temp->next = NULL;

    return head;
}

void printList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

int main(){
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);

    //head = rotateK(head, 2);
    head = rotateKOptimal(head, 2);

    printList(head);

    return 0;
}
