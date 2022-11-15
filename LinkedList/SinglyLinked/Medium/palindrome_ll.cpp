#include<iostream>
#include<vector>
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

// Noob approach
bool checkPalindromeNaive(Node* head){
    vector<int> v;

    while(head != NULL){
        v.push_back(head->data);
        head = head->next;
    }

    bool flag = false;

    int i = 0, j = v.size() - 1;
    while(i <= j){
        if(v[i] == v[j])
            flag = true;
        
        else{
            flag = false;
            return flag;
        }   

        i++;
        j--;
    }

    return flag;
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

// Space optimised
bool checkPalindrome(Node* head){
    Node* slow = head;
    Node* fast = head;

    // Find Middle
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse right half
    Node* temp = slow->next;
    Node* dummy = NULL;
    while(temp != NULL){
        Node* next = temp->next;
        temp->next = dummy;
        dummy = temp;
        temp = next;
    }

    slow->next = dummy;

    // Check left and right halves
    slow = slow->next;
    Node* check = head;
    while(slow != NULL){
        if(slow->data != check->data){
            return false;
        }
        else{
            check = check->next;
            slow = slow->next;
        }
    }

    return true;
}

int main(){
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 3);
    head = insert(head, 2);
    head = insert(head, 2);

    printList(head);

    cout << checkPalindrome(head) << endl;
    
    return 0;
}