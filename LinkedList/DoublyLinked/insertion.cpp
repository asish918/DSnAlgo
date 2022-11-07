#include<iostream>
using namespace std;

class Node {
    public:
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

Node* insertAtPos(Node* head, int value, int pos){
    Node* new_node = new Node(value);
    if(pos == 1){
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        return head;
    }

    int countPos = 1;

    Node* temp = head;
    while(temp != NULL){
        countPos++;
        temp = temp->next;
        if(countPos == pos)
            break;
    }

    new_node->next = temp->next;
    temp->next->prev = new_node;
    new_node->prev = temp;
    return head;
}

Node* insertAtFirst(Node* head, int value){
    Node* new_node = new Node(value);

    new_node->next = head;
    head->prev = new_node;
    head = new_node;
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

    head = insertAtFirst(head, 6);
    head = insertAtPos(head, 2, 1);

    printList(head);
    
    return 0;
}