#include <iostream>
#include <vector>
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

bool findPaths(struct Node* root, vector<int>& arr, int x){
   if(root == NULL)
        return false;

   arr.push_back(root->data);

   if(root->data == x)
       return true;

   if(findPaths(root->left, arr, x) || findPaths(root->right, arr, x))
       return true;

   arr.pop_back();
   return false;
}

int main(){
    struct Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);

    root->left->right = new Node(60);
    root->left->left = new Node(40);

    vector<int> path;
    findPaths(root, path, 30);
    
    for(auto i : path)
        cout << i << " ";
    return 0;
}
