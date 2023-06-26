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

int heightOfTree(struct Node* root){
    if(root == NULL) return 0;

    int lh = heightOfTree(root->left);
    int rh = heightOfTree(root->right);

    return 1 + max(lh, rh);
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
