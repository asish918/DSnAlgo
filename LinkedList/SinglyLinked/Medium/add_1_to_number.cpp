#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = NULL;
    }
};
Node* head = NULL;

Node* insert(Node* head, int val){
    Node* new_node = new Node(val);

    if(head == NULL)
        head = new_node;

    else{
        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = new_node;
    }

    return head;
}

Node* reverse(Node* head){
    Node* next = NULL;
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int addOneRecur(struct Node* head) {
    if(!head)
        return 1;

    int carry = addOneRecur(head->next);
    
    int sum = head->data + carry;
    head->data = sum % 10;
    return sum / 10;
}

Node* add_one_optimal(Node* head) {
    int carry = addOneRecur(head);

    if(carry) {
        Node* new_node = new Node(1);
        new_node->next = head;;
        head = new_node;
    }

    return head;
}

Node* add_one_noob(Node* head){
    Node* new_head = reverse(head);
    Node* curr = new_head; 
    Node* prev = NULL;
    int carry = 0;

    while(curr != NULL){
        int sum = 0;
        if(prev == NULL)
            sum = curr->data + 1;
        else
            sum = curr->data + carry;

        carry = sum / 10;
        curr->data = sum % 10;
        prev = curr;
        curr = curr->next;
    }

    if(carry){
        Node* new_node = new Node(1);
        prev->next = new_node;
    }

    return reverse(new_head);
}

void printList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    head = insert(head, 9);
    head = insert(head, 9);
    head = insert(head, 9);

    //head = add_one_noob(head);
    head = add_one_optimal(head);

    printList(head);
    return 0;
}
