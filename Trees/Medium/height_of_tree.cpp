#include <iostream>
#include<queue>
#include <algorithm>
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

int heightOfTree(struct Node* root){
    if(root == NULL) return 0;

    int lh = heightOfTree(root->left);
    int rh = heightOfTree(root->right);

    return 1 + max(lh, rh);
}

int levelOrderHeight(Node* root) {
    int level = 0;
    if(root == NULL) return level;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        level++;
        int size = q.size();
        
        while(size--) {
            auto i = q.front();
            q.pop();

            if(i->left) q.push(i->left);
            if(i->right) q.push(i->right);
        }
    }

    return level;
}

int main(){
    struct Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);

    root->right->right = new Node(7);
    root->right->left = new Node(15);
    
    cout << heightOfTree(root);

    return 0;
}
