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

Node* insert(Node* head, int value){
    Node* new_node = new Node(value);

    if(head == NULL){
        head = new_node;
        return head;
    }

    else{
        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = new_node;
        return head;
    }
}

Node* merge(Node* left, Node* right){
    if(left == NULL)
        return right;
    if(right == NULL)
        return left;
    if(left->data > right->data){
        Node* swap_temp = left;
        left = right;
        right = swap_temp;
    }

    Node* res = left;

    while(left != NULL && right != NULL){
       Node* temp = NULL;
       while(left != NULL && left->data <= right->data){
           temp = left;
           left = left->next;
       }

       temp->next = right;

       Node* swap_temp = left;
       left = right;
       right = swap_temp;
    }

    return res;
}

Node* findMid(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* mergeSort(Node* head){
    if(head == NULL || head->next == NULL)
        return head;

    Node* mid = findMid(head);

    Node* left = head;
    Node* right = mid->next;

    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    Node* ans = merge(left, right);
    return ans;
}

void printList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    
    head = insert(head, 4);
    head = insert(head, 5);
    head = insert(head, 3);
    head = insert(head, 2);
    head = insert(head, 1);

    printList(head);

    head = mergeSort(head);

    printList(head);

    return 0;
}
