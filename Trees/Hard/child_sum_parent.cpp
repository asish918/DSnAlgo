#include <climits>
#include<map>
#include<set>
#include<utility>
#include <cstdlib>
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<stack>
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

void preorder(Node* root) {
    queue<Node*> q;
    q.push(root);
    vector<vector<int>> ans;

    while(!q.empty()) {
        int size = q.size();
        vector<int> level;

        while(size--) {
            auto i = q.front();
            q.pop();

            level.push_back(i->data);

            if(i->left) q.push(i->left);
            if(i ->right) q.push(i->right);
        }
        
        ans.push_back(level);
    }

    for(auto i : ans) {
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }
    cout << "-----------" << endl;
}

void childSumTransform(Node* root) {
    if(root == NULL)
        return;
    int downSum = 0;

    if(root->left) downSum += root->left->data;
    if(root->right) downSum += root->right->data;

    if(downSum >= root->data) root->data = downSum;
    else {
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }

    childSumTransform(root->left);
    childSumTransform(root->right);

    int upSum = 0;
    if(root->left) upSum += root->left->data;
    if(root->right) upSum += root->right->data;
    if(root->left || root->right) root->data = upSum;
}

struct Node* createTree(int index, vector<int> data) {
    if(index >= data.size())
        return NULL;

    Node* root = new Node(data[index]);
    root->left = createTree(2 * index + 1, data);
    root->right = createTree(2 * index + 2, data);

    return root;
}

int main() {
    Node* root = createTree(0, {40, 10, 20, 2, 5, 30, 40});

//    Node* root = new Node(1);
//
//    root->left = new Node(2);
//    root->right = new Node(3);
//
//    root->left->left = new Node(4);
//
//    root->right->right = new Node(9);

    preorder(root);
    childSumTransform(root);
    preorder(root);

    return 0;
}

