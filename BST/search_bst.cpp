#include <iostream>
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

struct Node* searchBST(struct Node* root, int val){
    while(root != NULL && val != root->data)
        root = val < root->data ? root->left : root->right;

    return root;
}

int main(){
    struct Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);

    root->left->right = new Node(3);
    root->left->left = new Node(1);

    cout << searchBST(root, 7)->data;

    return 0;
}
