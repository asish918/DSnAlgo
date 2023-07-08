#include <algorithm>
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
    Node* predecessor = NULL;

    while(root) {
        if(k > root->data) {
            predecessor = root;
            root = root->right;
        }
        else 
            root = root->left;
    }

    if(predecessor)
        cout << predecessor->data << endl;
    else
        cout << "NULL" << endl;
}

//void optimal(Node* root, int k) {
//    Node* successor = NULL;
//
//    while(root) {
//        if(k >= root->data) {
//            root = root->right;
//        }
//        else {
//            successor = root;
//            root = root->left;
//        }
//    }
//
//    if(successor)
//        cout << successor->data << endl;
//    else 
//        cout << "NULL" << endl;
//} 
//
void inorderBrute(Node* root, vector<int>& traversal) {
    if(root == NULL)
        return;

    inorderBrute(root->left, traversal);
    traversal.push_back(root->data);
    inorderBrute(root->right, traversal);
}

void bruteForce(Node* root, int k) {
    vector<int> traversal;
    inorderBrute(root, traversal);
    if(k == traversal[traversal.size() - 1]) {
        cout << "NULL" << endl;
        return;
    }

    int iterator = upper_bound(traversal.begin(), traversal.end(), k) - traversal.begin();
    cout << traversal[iterator] << endl;
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
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 9);
    root = insert(root, 1);
    root = insert(root, 8);
    root = insert(root, 10);

    printTree(root);
    optimal(root, 5);
    bruteForce(root,  8);
    return 0;
}

/*
###### Optimal Approach Recursive way
 void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
       if(root == NULL)
            return;
        
        if(key < root->key) {
            suc = root;
            findPreSuc(root->left, pre, suc, key);
        }
        
        else if(key > root->key) {
            pre = root;
            findPreSuc(root->right, pre, suc, key);
        }
        else {
            if(root->left)
                findPreSuc(root->left, pre, suc, key);
            if(root->right)
                findPreSuc(root->right, pre, suc, key);
        }
*/
