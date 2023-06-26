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

void findPaths(struct Node* root, vector<int> row){
   if(root == NULL)
        return;

   row.push_back(root->data);

   if(root->left == NULL && root->right == NULL){
       for(auto i : row)
           cout << i << " ";
       cout << endl;
       return;
    }

   findPaths(root->left, row);
   findPaths(root->right, row);
}

int main(){
    struct Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);

    root->left->right = new Node(60);
    root->left->left = new Node(40);

    vector<int> row;
    findPaths(root, row);

    return 0;
}
