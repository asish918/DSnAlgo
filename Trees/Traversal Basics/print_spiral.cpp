#include<iostream>
#include<algorithm>
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

void levelOrder(Node* root) {
    vector<vector<int>> ans;
    int cnt = -1;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        cnt++;
        int size = q.size();
        vector<int> level;

        while(size--) {
            Node* node = q.front();
            q.pop();

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);

            level.push_back(node->data);
        }

        if(cnt % 2 == 0)
            reverse(level.begin(), level.end());

        ans.push_back(level);
    }

    for(auto i : ans) {
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(7);
    root->left->right = new Node(6);

    root->right->left = new Node(5);
    root->right->right = new Node(4);

    levelOrder(root);

    return 0;
}
