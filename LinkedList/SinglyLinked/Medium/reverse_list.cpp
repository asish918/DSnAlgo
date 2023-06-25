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

// Iterative
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

// Recursive
Node* revListRecur(Node* head){
    if(!head || !(head->next)) //Check for only head is required if NULL is passed initially: Edge Case 
        return head;

    Node* dummy = revListRecur(head->next);
    head->next->next = head;
    head->next = NULL;
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
    head = insert(head, 5);
    
    printlist(head);

    head = revListRecur(head);

    printlist(head);

    return 0;
}
