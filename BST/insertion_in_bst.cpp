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

struct Node* insertNode(struct Node* root, int value){
    if(root == NULL) return new Node(value);

    struct Node* curr = root;

    while(true){
        if(curr->data <= value){
            if(curr->right != NULL) curr = curr->right;
            else{
                curr->right = new Node(value);
                break;
            }
    }
        else{
            if(curr->left != NULL) curr = curr->left;
            else {
                curr->left = new Node(value);
                break;
            }
        }
    }
return root;
}

int main(){
    struct Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);

    root->left->right = new Node(3);
    root->left->left = new Node(1);

    return 0;
}
