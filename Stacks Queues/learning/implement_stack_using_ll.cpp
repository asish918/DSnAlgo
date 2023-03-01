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
Node* top = NULL;

Node* push(Node* head, Node* top, int val){
    Node* new_node = new Node(val);

    if(head == NULL){
        head = new_node;
        top = new_node;
    }

    else {
        top->next = new_node;
        top = top->next;
    }

    return head;
}

void printStack(Node* head, Node* top){
    while(head != top){
        cout << head->data << " ";
        head = head->next;
    }
}

int main(){
    head = push(head, top, 1);
    head = push(head, top, 2);
    head = push(head, top, 3);
    head = push(head, top, 4);

    printStack(head, top);
    return 0;
}
