#include <algorithm>
#include <iostream>
using namespace std;
int maxi = -1;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

int height(struct Node* root){
    if(root == NULL) return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return 1 + max(rh, lh);
}

int optimisedDiam(struct Node* root, int &maxi) {
    if(root == NULL) return 0;

    int lh = optimisedDiam(root->left, maxi);
    int rh = optimisedDiam(root->right, maxi);

    maxi = max(maxi, (lh + rh));
    return 1 + max(lh, rh);
}

void diameterOfTree(struct Node* root){
    if(root == NULL) return;

    int lh = height(root->left);
    int rh = height(root->right);

    maxi = max(maxi, (lh + rh));

    diameterOfTree(root->left);
    diameterOfTree(root->right);
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    optimisedDiam(root, maxi);

    cout << maxi << endl;

    return 0;
}
