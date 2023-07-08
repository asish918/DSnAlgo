#include <climits>
#include<iostream>
#include<vector>
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

//Apporach 1 (O n^2) Sort the preorder and get the inorder(inorder of BST is sorted). Use both to create a tree

struct Node* constructTree(vector<int> preorder, int* preIndex, int low, int high, int size){
    if(*preIndex >= size || low > high)
        return NULL;

    struct Node* root = new Node(preorder[*preIndex]);
    *preIndex = *preIndex + 1;

    if(low == high)
        return root;

    int i = 0;
    for(i = low; i<=high; i++)
        if(preorder[i] > root->data)
            break;

    root->left = constructTree(preorder, preIndex, *preIndex, i - 1, size);
    
    root->right = constructTree(preorder, preIndex, i + 1, high, size);

    return root;
}

// Apporach 2 O(n)

struct Node* buildTree(vector<int> preorder, int& index, int bound){
    if(index == preorder.size() || preorder[index] > bound)
        return NULL;
    
    struct Node* root = new Node(preorder[index++]);
    root->left = buildTree(preorder, index, root->data);
    root->right = buildTree(preorder, index, bound);

    return root;
}

void inorder(struct Node* root){
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    int preIndex = 0;
    //struct Node* root = constructTree(preorder, &preIndex, 0, preorder.size() - 1, preorder.size());

    struct Node* root = buildTree(preorder, preIndex, INT_MAX);
    inorder(root);    
    return 0;
}
