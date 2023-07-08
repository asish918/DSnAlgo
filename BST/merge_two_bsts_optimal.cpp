#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* findMid(Node* root) {
    Node* prev = NULL;
    Node* slow = root;
    Node* fast = root;

    while(fast && fast->right) {
        prev = slow;
        slow = slow->right;
        fast = fast->right->right;
    }

    if(prev)
        prev->right = NULL;

    return slow;
}

Node* buildTree(Node* root) {
    if(root == NULL)
        return NULL;

    Node* mid = findMid(root);
    Node* new_root = new Node(mid->data);

    if(root == mid)
        return mid;

    new_root->left = buildTree(root);
    new_root->right = buildTree(mid->right);

    return new_root;
}

Node* mergeTwoLists(Node* head1, Node* head2) {
    if(!head1)
        return head2;
    if(!head2)
        return head1;

    if(head1->data > head2->data) {
        Node* swap_temp = head1;
        head1 = head2;
        head2 = swap_temp;
    }

    Node* dummyHead = head1;

    while(head1 && head2) {
        Node* temp = NULL;
        while(head1 && head1->data <= head2->data) {
            temp = head1;
            head1 = head1->right;
        }

        temp->right = head2;

        Node* swap_temp = head1;
        head1 = head2;
        head2 = swap_temp;
    }

    return dummyHead;
}

Node* flattenTree(Node*& root) {
    Node* head = NULL;
    Node* prev = NULL;

    Node* curr = root;
    while(curr) {
        if(curr->left == NULL) { 
            if(prev == NULL) {
                prev = curr;
                head = curr;
            }
            else {
                prev->right = curr;
                prev = curr;
            }

            curr = curr->right;
        }
        else {
            Node* leftSubTree = curr->left;

            while(leftSubTree->right && leftSubTree->right != curr)
                leftSubTree = leftSubTree->right;

            if(leftSubTree->right == NULL) {
                leftSubTree->right = curr;
                curr = curr->left;
            }
            else {
                leftSubTree->right = NULL;

                if(prev == NULL) {
                    prev = curr;
                    head = curr;
                }
                else {
                    prev->right = curr;
                    prev = curr;
                }

                curr = curr->right;
            }
        }
    }

    return head;
}

void printList(Node* root) {
    cout << endl;
    while(root) {
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
    cout << "----------" << endl;
}

void printTree(Node* root) {
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();

        while(size--) {
            Node* node = q.front();
            q.pop();

            cout << node->data << " ";
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        cout << endl;
    }
    cout << "-------" << endl;
}

int main() {
    Node* root1 = new Node(12);
    root1->left = new Node(9);
    root1->left->left = new Node(6);
    root1->left->right = new Node(11);

    Node* root2 = new Node(8);
    root2->left = new Node(5);
    root2->right = new Node(10);
    root2->left->left = new Node(2);

    printTree(root1);
    printTree(root2);

    Node* head1 = flattenTree(root1);
    Node* head2 = flattenTree(root2);

    Node* final_head = mergeTwoLists(head1, head2);

    printList(final_head);
    printTree(buildTree(final_head));

    return 0;
}
