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

int leftHeight(struct Node* root){
    int ht = 0;
    while(root){
        ht++;
        root = root->left;
    }

    return ht;
}

int rightHeight(struct Node* root){
    int ht = 0;
    while(root){
        ht++;
        root = root->right;
    }

    return ht;
}

int countNodes(struct Node* root){
    if(root == NULL)
        return 0;

    int lh = leftHeight(root);
    int rh = rightHeight(root);

    if(lh == rh) return (1<<lh) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(5);
    root->left->left = new Node(6);

    cout << countNodes(root) << endl;

    return 0;
}
