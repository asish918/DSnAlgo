#include<iostream>
#include<queue>
#include<vector>
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

Node* insert(Node*root, int key) {
    if(root == NULL)
        return new Node(key);

    if(key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

void optimal(Node* root, int k) {
    vector<int> inorder;
    int counter = 0;
    Node* curr = root;

    while(curr) {
        if(curr->left == NULL) {
            inorder.push_back(curr->data);
            counter++;
            curr = curr->right;
        }
        else {
            Node* leftChild = curr->left;
            while(leftChild->right && leftChild->right != curr)
                leftChild = leftChild->right;

            if(leftChild->right == NULL) {
                leftChild->right = curr;
                curr = curr->left;
            }
            else {
                inorder.push_back(curr->data);
                counter++;
                leftChild->right = NULL;
                curr = curr->right;
            }
        }
        if(counter == k - 1) {
            cout << curr->data << endl;
            return;
        }
    }

    for(auto i : inorder)
        cout << i << " ";
    cout << endl;
} 

void inorderBrute(Node* root, vector<int>& traversal) {
    if(root == NULL)
        return;

    inorderBrute(root->left, traversal);
    traversal.push_back(root->data);
    inorderBrute(root->right, traversal);
}

void inorder(Node* root, int& count, int k) {
    if(root == NULL)
        return;

    inorder(root->left, count, k);
    count++;
    if(count == k) {
        cout << root->data << endl;
        return;
    }
    inorder(root->right, count, k);
}

void better(Node* root, int k) {
    int count = 0;
    inorder(root, count, k);
}

void bruteForce(Node* root, int k) {
    vector<int> traversal;
    inorderBrute(root, traversal);
    cout << traversal[k - 1] << endl;;
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

    cout << "-----------" << endl;
}

int main() {
    Node* root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);
    root = insert(root, 2);

    printTree(root);
    optimal(root, 5);
    //bruteForce(root,  3);
    //better(root, 3);
    return 0;
}
