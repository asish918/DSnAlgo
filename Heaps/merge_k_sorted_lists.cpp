#include <cstddef>
#include<iostream>
#include <vector>
#include <queue>
using namespace std;


class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(int val)
    {
        data = val;
        next = NULL;
    }
};

ListNode *head = NULL;

ListNode *insert(ListNode *head, int value)
{
    ListNode *new_node = new ListNode(value);

    if (head == NULL)
    {
        head = new_node;
    }

    else
    {
        ListNode *temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = new_node;
    }

    return head;
}


void printList(ListNode *head)
{
    ListNode *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

class cmp {
    public:
    bool operator() (ListNode* l1, ListNode* l2){
        return l1->data > l2->data;
    }
};

ListNode* mergeKSortedLists(vector<ListNode*> &v){
    priority_queue<ListNode*, vector<ListNode*>, cmp> q;

    ListNode* dummy = new ListNode(-1);
    ListNode* tail = dummy;

    for(int i = 0; i<v.size(); i++){
        if(v[i] != NULL)
            q.push(v[i]);
    }

    while(q.size()){
        ListNode* temp = q.top();
        tail->next = temp;
        tail = temp;
        q.pop();
        if(temp->next != NULL) q.push(temp->next);
    }

    return dummy->next;
}

int main(){
    ListNode* l1 = NULL;
    ListNode* l2 = NULL;
    ListNode* l3 = NULL;

    head = insert(head, 1);
    head = insert(head, 4);
    head = insert(head, 5);
    l1 = head;

    head = NULL;
    head = insert(head, 1);
    head = insert(head, 3);
    head = insert(head, 4);
    l2 = head;
    
    head = NULL;
    head = insert(head, 2);
    head = insert(head, 6);
    l3 = head;

    vector<ListNode*> lists;
    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);

    ListNode* ans = NULL;

    ans = mergeKSortedLists(lists);
    printList(ans);
    return 0;
}
