#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        prev = NULL;
        next = NULL;
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

Node* deleteNode(Node* head, Node* curr){
    if(head == curr)
        head = curr->next;
    if(curr->next != NULL)
        curr->next->prev = curr->prev;
    if(curr->prev != NULL)
        curr->prev->next = curr->next;

    free(curr);
    return head;
}

Node* deleteAllOccur(Node* head, int x){
    Node* curr = head;
    Node* next = NULL;

    while(curr != NULL){
        if(curr->data == x){
            next = curr->next;
            head = deleteNode(head, curr);
            curr = next;
        }
        else
            curr = curr->next;
    }

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
    head = insert(head, 2);
    head = insert(head, 2);
    head = insert(head, 10);
    head = insert(head, 8);
    head = insert(head, 4);
    head = insert(head, 2);
    head = insert(head, 5);
    head = insert(head, 2);

    head = deleteAllOccur(head, 2);

    printList(head);

    return 0;
}
