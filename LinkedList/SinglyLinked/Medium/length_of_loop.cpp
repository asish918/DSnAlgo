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

int detectLengthOfLoop(Node* &head){
    // creating dummy cycle
    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    
    Node* new_node = new Node(9);
    temp->next = new_node;
    new_node->next = head;
    
    Node* fast = head;
    Node* slow = head;

    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast){
            int count = 1;
            slow = slow->next;

            while(slow!=fast){
                count++;
                slow = slow->next;
            }

            return count;
        }
    }

    return 0;
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


    cout << detectLengthOfLoop(head) << endl;
    printList(head);
    
    return 0;
}