#include <climits>
#include<unordered_map>
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

void markParents(Node* root, Node*& target_node, int target, unordered_map<Node*, Node*>& parent_track) {
    if(root == NULL)
        return;

    if(root->data == target)
        target_node = root;

    if(root->left) parent_track[root->left] = root;
    if(root->right) parent_track[root->right] = root;

    markParents(root->left, target_node, target, parent_track);
    markParents(root->right, target_node, target, parent_track);
}

//Similar to Find nodes till K
int findMinTime(Node* root, int target, vector<int>& ans) {
    unordered_map<Node*, Node*> parent_track;
    unordered_map<Node*, bool> visited;
    Node* target_node = NULL;
    
    markParents(root, target_node, target, parent_track);

    queue<Node*> q;
    q.push(target_node);
    visited[target_node] = true;

    int maxi = 0;

    while(!q.empty()) {
        int size = q.size();
        bool burned = false;
        while(size--) {
            Node* node = q.front();
            q.pop();

            if(node->left && !visited[node->left]) {
                burned = true;
                q.push(node->left);
                visited[node->left] = true;
            }

            if(node->right && !visited[node->right]) {
                burned = true;
                q.push(node->right);
                visited[node->right] = true;
            }

            if(parent_track[node] && !visited[parent_track[node]]) {
                burned = true;
                q.push(parent_track[node]);
                visited[parent_track[node]] = true;
            }
        }

        if(burned) maxi++; 
    }

    return maxi;
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
    Node* root = createTree(0, {1, 2, 3, 4, 5, NULL, 6, NULL, NULL, 7, 8, NULL, 9, 10, 11, NULL, NULL, NULL, 12, NULL, NULL, NULL, 13});

//    Node* root = new Node(20);
//
//    root->left = new Node(8);
//    root->right = new Node(22);
//
//    root->left->left = new Node(4);
//    root->left->right = new Node(12);
//
//    root->left->right->left = new Node(10);
//    root->left->right->right = new Node(14);

    vector<int> ans;
    int target = 8;
    cout << findMinTime(root, target, ans) << endl;

    return 0;
}

