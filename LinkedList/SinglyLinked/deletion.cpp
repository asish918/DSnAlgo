#include<iostream>
using namespace std;

class ListNode {
    public:
    int data;
    ListNode* next;

    ListNode(int val){
        data = val;
        next = NULL;
    }
};

ListNode* head = NULL;

ListNode* insert(ListNode* head, int value){
    ListNode* new_node = new ListNode(value);

    if(head == NULL){
        head = new_node;
        return head;
    }

    ListNode* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    
    temp->next = new_node;
    return head;
}

ListNode* deleteAtPos(ListNode* head, int x){
    if(x == 1){
        ListNode* temp = head->next;
        free(head);
        head = temp;
        return head;
    }

    int countPos = 1;
    ListNode* temp = head;

    while(temp != NULL){
        countPos++;
        if(countPos == x)
            break;

        temp = temp->next;
    }

    ListNode* del = temp->next;
    temp->next = temp->next->next;
    free(del);
    return head;
}

void printList(ListNode* head){
    ListNode* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    head = insert(head, 1);
    head = insert(head, 4);
    head = insert(head, 5);
    head = insert(head, 9);
    head = insert(head, 2);

    head = deleteAtPos(head, 1);

    printList(head);
    
    return 0;
}