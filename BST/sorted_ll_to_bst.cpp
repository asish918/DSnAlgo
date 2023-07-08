#include<iostream>
#include<queue>
using namespace std;

struct NodeLL {
    int data;
    NodeLL* next;

    NodeLL(int val) {
        data = val;
        next = NULL;
    }
};

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

NodeLL* findMid(NodeLL* head) {
    NodeLL* prev = NULL;
    NodeLL* fast = head;
    NodeLL* slow = head;

    while(fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if(prev)
        prev->next = NULL;

    return slow;
}

TreeNode* buildTree(NodeLL* head) {
    if(head == NULL)
        return NULL;

    NodeLL* mid = findMid(head);
    TreeNode* root = new TreeNode(mid->data);

    if(mid == head)
        return root;

    root->left = buildTree(head);
    root->right = buildTree(mid->next);

    return root;
}

void printTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();

        while(size--) {
            TreeNode* node = q.front();
            q.pop();

            cout << node->data << " ";
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        cout << endl;
    }
    cout << "-----------" << endl;
}

void printList(NodeLL* head) {
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    NodeLL* head = new NodeLL(1);
    head->next = new NodeLL(2);
    head->next->next = new NodeLL(3);
    head->next->next->next = new NodeLL(4);
    head->next->next->next->next = new NodeLL(5);
    head->next->next->next->next->next = new NodeLL(6);

    TreeNode* root = buildTree(head);
    printTree(root);

    return 0;
}

/*
// Function to find the middle element of a linked list
ListNode* findMiddle(ListNode* head) {
    ListNode* prevPtr = nullptr;
    ListNode* slowPtr = head;
    ListNode* fastPtr = head;

    while (fastPtr != nullptr && fastPtr->next != nullptr) {
        prevPtr = slowPtr;
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    if (prevPtr != nullptr)
        prevPtr->next = nullptr;

    return slowPtr;
}

// Function to convert a sorted linked list to a binary search tree
TreeNode* sortedListToBST(ListNode* head) {
    if (head == nullptr)
        return nullptr;

    ListNode* midNode = findMiddle(head);
    TreeNode* root = new TreeNode(midNode->val);

    if (head == midNode)
        return root;

    root->left = sortedListToBST(head);
    root->right = sortedListToBST(midNode->next);

    return root;
}
*/
