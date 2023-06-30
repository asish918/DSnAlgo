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
    priority_queue<ListNode*, vector<ListNode*>, cmp> q; //min-heap

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

/*
The code starts by declaring a priority queue q of ListNode pointers. It uses the cmp comparator to compare the ListNode pointers. The cmp comparator should be defined separately in the code.

It then creates a dummy ListNode with a value of -1 and initializes a tail pointer to the dummy node. This dummy node will serve as the head of the merged list, and the tail pointer will be used to keep track of the last node in the merged list.

Next, the code iterates through each ListNode pointer in the vector v. If the current ListNode pointer is not NULL, it means there are still elements in that linked list, so it pushes that ListNode pointer into the priority queue q.

After inserting all the ListNode pointers into the priority queue, the code enters a loop that continues until the priority queue q becomes empty.

Inside the loop, it retrieves the top element (ListNode with the smallest value) from the priority queue q using q.top(). This ListNode will be the next node in the merged list.

The code appends this node to the merged list by setting tail->next to the current node and then updating the tail pointer to the current node. This adds the node to the end of the merged list.

It then removes the top element from the priority queue using q.pop(), as it has already been added to the merged list.

If the next pointer of the current node is not NULL, it means there are more nodes remaining in that linked list. So, the code pushes the next node of the current node into the priority queue q using q.push(temp->next).

The loop continues until all the ListNode pointers have been processed and the priority queue q becomes empty.

Finally, the code returns the next node of the dummy node, which is the head of the merged list.
 */
