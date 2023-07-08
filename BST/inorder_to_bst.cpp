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
    cout << "---------" << endl;
}

Node* constructBST(vector<int>& inorder, int left, int right) {
    if(left > right) 
        return NULL;

    int mid = (right - left)/2 + left;
    Node* new_node = new Node(inorder[mid]);
    new_node->left = constructBST(inorder, left, mid - 1);
    new_node->right = constructBST(inorder, mid + 1, right);

    return new_node;
}

int main() {
    vector<int> inorder = {1, 2, 3, 4, 5, 6};

    Node* root = constructBST(inorder, 0, inorder.size() - 1);

    printTree(root);
    return 0;
}
