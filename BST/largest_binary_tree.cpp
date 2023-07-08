#include <climits>
#include<iostream>
#include<queue>
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

class NodeVal {
    public:
        int minVal;
        int maxVal;
        int maxSize;

        NodeVal(int min, int max, int size) {
            this->minVal = min;
            this->maxVal = max;
            this->maxSize = size;
        }
};

NodeVal largestSubtreeFinder(Node* root) {
    if(root == NULL)
        return NodeVal(INT_MAX, INT_MIN, 0);

    NodeVal left = largestSubtreeFinder(root->left);
    NodeVal right = largestSubtreeFinder(root->right);

    if(left.maxVal < root->data && root->data < right.minVal) {
        return NodeVal(min(root->data, left.minVal), max(root->data, right.maxVal), 1 + left.maxSize + right.maxSize);
    }

    return NodeVal(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
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
    cout << "----------" << endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(4);
    root->right = new Node(4);

    root->left->left = new Node(6);
    root->left->right = new Node(8);

    printTree(root);
    cout << largestSubtreeFinder(root).maxSize << endl;

    return 0;
}

/*
####Brute Force

Use validate each and every single node in the tree using valid_bst(solved question), the moment you find a valid node, do a traversal of the entire tree and calculate the size and return;
*/
