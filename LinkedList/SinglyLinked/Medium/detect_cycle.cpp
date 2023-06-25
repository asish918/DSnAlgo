#include<iostream>
#include<unordered_set>
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

bool detectCycleNaive(Node* head){
   if(head == NULL || head->next == NULL)
    return false;

    Node* temp = head;
    unordered_set<Node*> check;

    while(temp != NULL){
        if(check.find(temp) != check.end())
            return true;
        
        check.insert(temp);
        temp = temp->next;
    }

    return false;
}

bool detectCycle(Node*& head){
    // creating dummy cycle for testing
    Node* new_node = new Node(10);
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
    new_node->next = head->next->next;
    //

    if(head == NULL || head->next == NULL)
        return false;

    Node* fast = head;
    Node* slow = head;

    while(fast != NULL && fast->nextt != NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow)
            return true;
    }

    return false;
}

void printList(Node* head){
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

    // printList(head);
    
    cout << detectCycle(head) << endl;
    cout << detectCycleNaive(head) << endl;

    return 0;
}
