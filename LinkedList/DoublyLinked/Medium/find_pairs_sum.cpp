#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int value){
        data = value;
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

void findPairsNoob(Node* head, int x){
    Node* temp1 = head;
    Node* temp2 = head;

    while(temp1 != NULL){
        temp2 = temp1;
        while(temp2 != NULL){
            if(temp1->data + temp2->data == x)
                cout << temp1->data << " " << temp2->data << endl;

            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

void findPairsOptimised(Node* head, int x){
    Node* first = head;
    Node* last = head;
    while(last->next != NULL)
        last = last->next;

    while(first != last){
        if(first->data + last->data == x){
            cout << first->data << " " << last->data << endl;
            first = first->next;
            last = last->prev;
        }

        else if(first->data + last->data < x)
            first = first->next;
        else
            last = last->prev;
    }
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
    head = insert(head, 2);
    head = insert(head, 4);
    head = insert(head, 5);
    head = insert(head, 6);
    head = insert(head, 8);
    head = insert(head, 9);

    //findPairsNoob(head, 7);
    findPairsOptimised(head, 7);
    printList(head);

    return 0;
}
