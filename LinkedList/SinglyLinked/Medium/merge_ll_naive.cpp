#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

struct Node* mergeList(struct Node* left, struct Node* right) {
    Node* dummy = new Node(-1);
    Node* node = dummy;

    while(left && right) {
        if(left->data < right->data) {
            node->next = left;
            left = left->next;
        }
        else {
            node->next = right;
            right = right->next;
        }
        node = node->next;
    }

    if(left)
        node->next = left;
    if(right)
        node->next = right;

    return dummy->next;
}

struct Node* mergeSort(struct Node* head) {
    if(head == NULL || head->next == NULL)
        return head;

    Node* fast = head->next->next;
    Node* slow = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* left = head;
    Node* right = slow->next;
    slow->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);
    return mergeList(left, right);
}

struct Node* insertAtBack(struct Node* head, int value) {
    if(!head){
        head = new Node(value);
        return head;
    }
    else {
        struct Node* new_node = new Node(value);
        struct Node* temp = head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = new_node;
        return head;
    }
}

void printList(struct Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    head = insertAtBack(head, 5);
    head = insertAtBack(head, 4);
    head = insertAtBack(head, 3);
    head = insertAtBack(head, 2);
    head = insertAtBack(head, 1);

    printList(head);
    head = mergeSort(head);
    printList(head);
    return 0;
}
