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

Node* startOfLoop(Node* &head){
    // creating dummy cycle
    Node* new_node = new Node(9);
    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
    new_node->next = head;
    
    Node* slow = head;
    Node* fast = head;
    Node* entry = head;

    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast){
            while(entry != slow){
                slow = slow->next;
                entry = entry->next;
            }

            return entry;
        }
    }

    return NULL;
}

void printList(Node* head){
    Node* temp = head;
    while(temp->next != head){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

int main(){
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);

    cout << startOfLoop(head)->data << endl;
    // printList(head);
    
    return 0;
}