#include<iostream>
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
// Leetcode variant
Node* segregateOddEvenLeetCode(Node* head){
   Node* odd = head;
   Node* even = head->next;
   Node* evenHead = even;

   while(odd->next && even->next){
       odd->next = even->next;
       even->next = odd->next->next;
       odd = odd->next;
       even = even->next;
   }

   odd->next = evenHead;

    return head;
}

Node* segregateOddEvenGFG(Node* head){
    Node* evenHead = new Node(-1);
    Node* oddHead = new Node(-1);

    Node* even = evenHead;
    Node* odd = oddHead;

    while(head){
        if(head->data % 2 != 0){
            odd->next = head;
            odd = odd->next;
        }

        else{
            even->next = head;
            even = even->next;
        }

        head = head->next;
    }

    odd->next = evenHead->next;
    even->next = NULL;
    return oddHead->next;
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
    head = insert(head, 5);

    printList(head);

    head = segregateOddEvenGFG(head);

    printList(head);
    
    return 0;
}