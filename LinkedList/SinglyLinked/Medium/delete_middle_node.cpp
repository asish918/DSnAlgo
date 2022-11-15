#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *head = NULL;

Node *insert(Node *head, int value)
{
    Node *new_node = new Node(value);

    if (head == NULL)
    {
        head = new_node;
        return head;
    }

    else
    {
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = new_node;
        return head;
    }
}

Node* deleteMiddleLeetCode(Node* head){
    if(head->next == NULL)
        return head;
    
    Node* fast = head->next->next;
    Node* slow = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = slow->next->next;
    return head;
}

Node* deleteMiddleGFG(Node* head){
    if(head->next == NULL)
        return head;
    
    Node* slow = head;
    Node* fast = head;
    Node* prevSlow = head;

    while(fast->next && fast->next->next){
        prevSlow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prevSlow->next = slow->next;
    return head;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main()
{
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);
    // head = insert(head, 6);

    printList(head);
    // head = deleteMiddleLeetCode(head);
    head = deleteMiddleGFG(head);
    printList(head);
    return 0;
}