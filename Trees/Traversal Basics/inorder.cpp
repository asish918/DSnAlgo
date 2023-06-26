#include <iostream>
#include <stack>
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

void inorder(struct Node* root){
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void iterative_inorder(struct Node* root) {
    vector<int> inorder;
    Node* node = root;
    stack<Node*> st;
    while(true){
        if(node != NULL){
            st.push(node);
            node = node->left;
        }
        else {
            if(st.empty()) break;
            node = st.top();
            st.pop();
            inorder.push_back(node->data);
            node = node->right;
        }
    }

    for(auto i : inorder)
        cout << i << " ";
}

int main(){
    struct Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);

    root->left->left = new Node(40);
    root->left->right = new Node(60);

    root->right->left = new Node(50);

    inorder(root);
    cout << endl;
    iterative_inorder(root);

    return 0;
}
