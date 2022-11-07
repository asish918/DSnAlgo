#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int val){
        data = val;
        prev = NULL;
        next = NULL;
    }
};

Node* head = NULL;

Node* insert(Node* head, int value){
    Node* new_node = new Node(value);

    if(head == NULL){
        head = new_node;
        return head;
    }

    else {
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = new_node;
        new_node->prev = temp;
        return head;
    }
}

Node* reverse_list(Node* head){
    Node* curr = head;
    Node* temp = NULL;

    while(curr != NULL){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if(temp != NULL)
        head = temp->prev;
    
    return head;
}

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);

    head = reverse_list(head);

    printList(head);
    
    return 0;
}