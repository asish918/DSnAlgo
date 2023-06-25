#include <cstddef>
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

Node* sort_approach_1(Node* head){
    int zero = 0, one = 0, two = 0;

    Node* temp = head;

    while(temp != NULL){
        if(temp->data == 0)
            zero++;
        else if(temp->data == 1)
            one++;
        else
            two++;

        temp = temp->next;
    }

    temp = head;

    while(temp != NULL){
        if(zero>0){
            temp->data = 0;
            zero--;
        }
        else if(one>0){
            temp->data = 1;
            one--;
        }
        else{
            temp->data = 2;
            two--;
        }
        
        temp = temp->next;
    }

    return head;
}

Node* sort_approach_2(Node* head){
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneTail = oneHead;
    Node* twoTail = twoHead;

    Node* temp = head;

    while(temp != NULL){
        if(temp->data == 0){
            zeroTail->next = temp;
            zeroTail = zeroTail->next;
        }
        else if(temp->data == 1){
            oneTail->next = temp;
            oneTail = oneTail->next;
        }
        else {
            twoTail->next = temp;
            twoTail = twoTail->next;
        }

        temp = temp->next;
    }

    if(oneHead->next != NULL){
        zeroTail->next = oneHead->next;
    }
    else {
        zeroTail->next = twoHead->next;
    }

    
    oneTail->next = twoHead->next;

   Node* new_head = zeroHead->next;

   delete oneHead;
   delete twoHead;
   delete zeroHead;

   return new_head;
}

Node* insert(Node* head, int value){
    Node* new_node = new Node(value);

    if(head == NULL)
        head = new_node;
    else{
        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
    };
    
    return head;
}

void printList(Node* head){
    while(head!=NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    head = insert(head, 2);
    head = insert(head, 2);
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 1);

    //head = sort_approach_1(head);
    head = sort_approach_2(head);
    
    printList(head);

    return 0;
}
