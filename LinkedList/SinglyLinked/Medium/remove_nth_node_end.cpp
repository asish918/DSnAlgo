#include <iostream>
using namespace std;

struct Node {
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

// Noob Approach
//Node* removeNthNodeEnd(Node* head, int n){
    //Node* temp = head;
//
    //int count = 0;
    //while(temp != NULL){
        //count++;
        //temp = temp->next;
    //}
//
    //if(n == count){
        //Node* del_temp = head;
        //head = head->next;
        //free(del_temp);
        //return head;
    //}
//
    //int nth_node = count - n;
//
    //int i = 1;
    //Node* del_dummy = head;
    //while(i < nth_node){
       //del_dummy = del_dummy->next;
       //i++;
    //}
//
    //cout << del_dummy->data << endl;
    //del_dummy->next = del_dummy->next->next;
    //return head;
//}

Node* removeNthNodeEnd(Node* head, int n){
    Node* dummy = new Node(-1);
    dummy->next = head;
    Node* slow = dummy;
    Node* fast = dummy;

    int i = 0;
    while(i < n){
        fast = fast->next;
        i++;
    }

    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;
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
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    
    printList(head);
    head = removeNthNodeEnd(head, 4);
    printList(head);

    return 0;
}
