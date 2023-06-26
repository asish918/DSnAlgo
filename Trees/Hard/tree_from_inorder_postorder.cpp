#include <iostream>
#include <vector>
#include <map>
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

struct Node* buildTree(vector<int> preorder, int preStart, int preEnd, vector<int> inorder, int inStart, int inEnd, map<int, int>& inMap){
    if(preStart > preEnd || inStart > inEnd) return NULL;

    struct Node* root = new Node(preorder[preEnd]);

    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = buildTree(preorder, preStart, preStart + numsLeft - 1, inorder, inStart, inRoot - 1, inMap);

    root->right = buildTree(preorder, preStart + numsLeft, preEnd - 1, inorder, inRoot + 1, inEnd, inMap);

    return root;
}

void inorderTraversal(struct Node* root){
    if(root == NULL)
        return;

    cout << root->data << " ";
    inorderTraversal(root->left);
    inorderTraversal(root->right);
}

int main(){
    vector<int> postorder{9, 15, 7, 20, 3};
    vector<int> inorder{9, 3, 15, 20, 7};

    map<int, int> inMap;
    for(int i = 0; i<inorder.size(); i++)
        inMap[inorder[i]] = i;

    struct Node* head = buildTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);

    inorderTraversal(head);

    return 0;
}
