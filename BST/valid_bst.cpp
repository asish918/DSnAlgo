#include <climits>
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

struct Node* head = NULL;

bool isValid(struct Node* root, long minVal, long maxVal){
    if(root == NULL)
        return true;

    if(root->data >= maxVal || root->data <= minVal)
        return false;

    return isValid(root->left, minVal, root->data) && isValid(root->right, root->data, maxVal);
}

int main(){
    head = new Node(5);
    head->left = new Node(1);
    head->right = new Node(4);

    head->right->left = new Node(3);
    head->right->right = new Node(6);

    cout << isValid(head, INT_MIN, INT_MAX);

    return 0;
}
