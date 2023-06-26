#include <climits>
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

int maxPathDown(struct Node* root, int& sum){
    if(root == NULL) return 0;

    int leftSum = max(0, maxPathDown(root->left, sum));

    int rightSum = max(0, maxPathDown(root->right, sum));

    sum = max(sum, leftSum + rightSum + root->data);
    return root->data + max(leftSum, rightSum);
}

int maxPathSum(struct Node* root){
    int maxi = INT_MIN;
    maxPathDown(root, maxi);
    return maxi;
}

int main(){
    struct Node* root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);

    root->right->right = new Node(7);
    root->right->left = new Node(15);

    cout << maxPathSum(root);
    return 0;
}
