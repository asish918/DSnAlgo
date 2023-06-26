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

bool checkSymmetry(struct Node* left, struct Node* right){
    if(left == NULL || right == NULL)
        return left == right;

    if(left->data != right->data) return false;

    return checkSymmetry(left->left, right->right) && checkSymmetry(left->right, right->left);
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);

    root->left->left = new Node(3);
    root->left->right = new Node(4);

    root->right->left = new Node(4);
    root->right->right = new Node(3);

    cout << checkSymmetry(root->left, root->right) << endl;

    return 0;
}
