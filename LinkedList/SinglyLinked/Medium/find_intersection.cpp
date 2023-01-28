#include<iostream>
#include<cstdlib>
#include<unordered_map>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

Node* head1 = NULL;
Node* head2 = NULL;

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

void createIntersection(Node* &head1, Node* &head2){
    Node* dummy = NULL;
    dummy = insert(dummy, 8);
    dummy = insert(dummy, 7);
    dummy = insert(dummy, 6);

    Node* temp1 = head1;
    Node* temp2 = head2;

    while(temp1->next)
        temp1 = temp1->next;

    while(temp2->next)
        temp2 = temp2->next;

    temp1->next = dummy;
    temp2->next = dummy;
}

// Noob brute force
Node* find_intersection_noob(Node* head1, Node* head2){
    Node* temp = head1;

    while(head2){
        head1 = temp;
        while(head1){
            if(head1 == head2)
                return head1;

            head1 = head1->next;
        }
        head2 = head2->next;
    }

    return NULL;
}

Node* find_intersection_better(Node* head1, Node* head2){
    unordered_map<Node*, int> m;

    Node* temp = head1;
    while(temp != NULL){
        m[temp] = 1;
        temp = temp->next;
    }

    temp = head2;
    while(temp != NULL){
        if(m.find(temp) != m.end()){
            return temp;
        }
        
        temp = temp->next;
    }

    return NULL;
}

Node* find_intersection_optimal1(Node* head1, Node* head2){
    int length1 = 0;
    int length2 = 0;

    Node* temp1 = head1;
    Node* temp2 = head2;

    while(temp1 != NULL || temp2 != NULL){
        if(temp1 != NULL){
            length1++;
            temp1 = temp1->next;
        }
           
        else if(temp2 != NULL){
            length2++;
            temp2 = temp2->next;
        }   
    }
    
    int diff = abs(length1 - length2);

    temp1 = head1;
    temp2 = head2;

    while(diff--){
        if(length2 > length1)
            temp2 = temp2->next;
        else if(length1 > length2){
            temp1 = temp1->next;
        }
    }

    while(temp1 != NULL && temp2 != NULL){
        if(temp1 == temp2)
            return temp1;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return NULL;
}

// Best
Node* find_intersection_optimal2(Node* head1, Node* head2){
    if(head1 == NULL || head2 == NULL) return NULL;

    Node* temp1 = head1;
    Node* temp2 = head2;

    while(temp1 != temp2){
        temp1 = (temp1 == NULL) ? head2 : temp1->next;
        temp2 = (temp2 == NULL) ? head1 : temp2->next;
    }

    return temp1;
}

void printList(Node* head){
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    head1 = insert(head1, 1);
    head1 = insert(head1, 2);

    head2 = insert(head2, 2);
    head2 = insert(head2, 8);
    head2 = insert(head2, 1);
    head2 = insert(head2, 3);

    createIntersection(head1, head2);

    printList(head1);
    printList(head2);

    //Node* ans = find_intersection_noob(head1, head2);
    //Node* ans = find_intersection_better(head1, head2);
    Node* ans = find_intersection_optimal1(head1, head2);

    if(ans)
        cout << ans->data << " " << endl;
    else
     cout << "NUMLL" << endl;

    return 0;
}
