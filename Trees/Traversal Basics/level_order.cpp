#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void levelOrder(struct Node* root){
    vector<vector<int> > ans;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> level;

        for(int i = 0; i<size; i++){
            Node* node = q.front();
            q.pop();
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
            level.push_back(node->data);
        }

        ans.push_back(level);
    }

    for(auto i : ans){
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

int main(){
    struct Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);

    root->left->left = new Node(40);
    root->left->right = new Node(60);

    root->right->left = new Node(50);

    levelOrder(root);

    return 0;
}
