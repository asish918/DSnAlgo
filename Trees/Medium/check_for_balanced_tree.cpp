#include <iostream>
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

int checkBalancedOptimised(struct Node* root){
    if(root == NULL)
        return 0;

    int lh = checkBalancedOptimised(root->left);
    if(lh == -1) return -1;
    int rh = checkBalancedOptimised(root->right);
    if(rh == -1) return -1;

    if(abs(lh - rh) > 1) return -1;

    return 1 + max(lh, rh);
}

int heightOfTree(struct Node* root){
    if(root == NULL) return 0;

    int lh = heightOfTree(root->left);
    int rh = heightOfTree(root->right);

    return 1 + max(lh, rh);
}

bool checkBalanced(struct Node* root){
    if(root == NULL) return true;

    int lh = heightOfTree(root->left);
    int rh = heightOfTree(root->right);

    if(abs(rh - lh) > 1) return false;
    
    bool left = checkBalanced(root->left);
    bool right = checkBalanced(root->right);

    return left && right;
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);

    root->left->right = new Node(4);
    root->left->left = new Node(5);

    root->left->left->left = new Node(7);
    root->left->left->right = new Node(6);
    
    cout << checkBalanced(root);
    cout << endl;
    cout << checkBalancedOptimised(root);
    return 0;
}
