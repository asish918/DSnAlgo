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


void morris_traversal_preorder(struct Node* root){
    struct Node* cur = root;

    while(cur != NULL){
        if(cur->left == NULL){
            cout << cur->data << " ";
            cur = cur->right;
        }
        else {
            struct Node* prev = cur->left;
            while(prev->right && prev->right != cur)
                prev = prev->right;

            if(prev->right == NULL){
                prev->right = cur;
                cout << cur->data << " ";
                cur = cur->left;
            }
            else {
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
}

void morris_traversal_inorder(struct Node* root){
    struct Node* cur = root;

    while(cur != NULL){
        if(cur->left == NULL){
            cout << cur->data << " ";
            cur = cur->right;
        }
        else {
            struct Node* prev = cur->left;
            while(prev->right && prev->right != cur)
                prev = prev->right;

            if(prev->right == NULL){
                prev->right = cur;
                cur = cur->left;
            }
            else {
                prev->right = NULL;
                cout << cur->data << " ";
                cur = cur->right;
            }
        }
    }
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(5);

    morris_traversal_inorder(root);
    cout << endl;
    morris_traversal_preorder(root);

    return 0;
}
