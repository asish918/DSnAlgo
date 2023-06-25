#include<iostream>
using namespace std;

struct Node{
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

Node* removeDuplicates(Node* head){
    Node* fast = head;
    Node* slow = head;

    while(fast != NULL){
        if(fast->data != slow->data){
            slow->next = fast;
            fast->prev = slow;
            slow = fast;
        }
        else
            fast = fast->next;
    }

    slow->next = NULL;

    return head;
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
    head = insert(head, 1);
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);

    head = removeDuplicates(head);

    printList(head);

    return 0;
}

/*
 The function removeDuplicates takes a pointer to a pointer of the head of the doubly linked list as the parameter.
It initializes two pointers, fast and slow, to the head of the list.
The fast pointer is used to iterate through the list to check for duplicates.
The slow pointer is used to keep track of the current non-duplicate element.
The loop continues until the fast pointer reaches the end of the list.
Inside the loop, it checks if the data of fast and slow nodes are different.
If they are different, it means a non-duplicate element is found.
In this case, it updates the next and prev pointers of slow and fast nodes to maintain the list structure.
Then, it moves the slow pointer to the next non-duplicate element.
If they are the same, it means a duplicate element is found. In this case, it moves the fast pointer to the next node.
After the loop ends, it sets the next pointer of the last non-duplicate element (pointed by slow) to NULL.
 */
