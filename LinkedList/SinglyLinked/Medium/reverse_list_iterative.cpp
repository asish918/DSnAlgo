#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
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
        while(temp->next != NULL)
            temp = temp->next;
        
        temp->next = new_node;
        return head;
    }
}

Node* revList(Node* head){
    Node* dummy = NULL;
    while(head != NULL){
        Node* next = head->next;
        head->next = dummy;
        dummy = head;
        head = next;
    }
    return dummy;
}

void printlist(Node* head){
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
    
    printlist(head);

    head = revList(head);

    printlist(head);

    return 0;
}