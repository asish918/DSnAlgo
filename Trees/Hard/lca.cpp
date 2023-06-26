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

struct Node* lca_optimised(struct Node* root, int p, int q){
    if(root == NULL || root->data == p || root->data == q)
        return root;

    struct Node* left = lca_optimised(root->left, p, q);
    struct Node* right = lca_optimised(root->right, p, q);

    if(left == NULL)
        return right;
    else if(right == NULL)
        return left;
    else
        return root;
}

int lca(struct Node* root, int p, int q){
    vector<int> path_p;
    vector<int> path_q;

    findPaths(root, path_p, p);
    findPaths(root, path_q, q);

    int i = 0;
    while(i < path_p.size() && i < path_q.size()){
        if(path_p[i] != path_q[i])
            return path_p[i-1];

        i++;
    }

    return -1;
}


int main(){
    vector<int> arr;
    struct Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);

    root->left->right = new Node(2);
    root->left->left = new Node(6);

    root->right->left = new Node(0);
    root->right->right = new Node(8);

    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    cout << lca(root, 7, 4) << endl;
    cout << lca_optimised(root, 7, 4)->data;

    return 0;
}
