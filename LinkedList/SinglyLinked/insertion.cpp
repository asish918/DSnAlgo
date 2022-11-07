#include <iostream>
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

ListNode *insertAtFirst(ListNode *head, int value)
{
    ListNode *new_node = new ListNode(value);
    new_node->next = head;
    head = new_node;
    return head;
}

ListNode *insertAtEnd(ListNode *head, int value)
{
    ListNode *new_node = new ListNode(value);
    ListNode *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new_node;
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

int main()
{
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);

    head = insertAtFirst(head, 5);
    head = insertAtEnd(head, 6);

    printList(head);

    cout << endl;

    return 0;
}