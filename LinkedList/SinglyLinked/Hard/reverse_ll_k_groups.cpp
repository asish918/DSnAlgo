#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

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
        new_node->prev = temp;
        return head;
    }
}

struct Node* reverse_k_groups(struct Node* head, int k, int size) {
    if(head==nullptr || size<k) return head;

    Node* prev=nullptr, *cur=head, *next=nullptr;
    int count=0;
    while(cur!=nullptr && count<k){
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
        count++;
    }

    head->next=reverse_k_groups(next, k, size - k);

    return prev;
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
    head = insertAtBack(head, 1);
    head = insertAtBack(head, 2);
    head = insertAtBack(head, 2);
    head = insertAtBack(head, 4);
    head = insertAtBack(head, 5);
    head = insertAtBack(head, 6);
    head = insertAtBack(head, 7);
    head = insertAtBack(head, 8);

    printList(head);
    head = reverse_k_groups(head, 4, 8);
    printList(head);
    return 0;
}
