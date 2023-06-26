#include <iostream>
#include <vector>
#include <stack>
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

void preorder(struct Node* root){
    if(root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void iterative_preorder(struct Node* root){
    vector<int> preorder;
    stack <Node*> st;
    st.push(root);

    while(!st.empty()){
        Node* node = st.top();
        st.pop();
        preorder.push_back(node->data);

        if(node->right != NULL)
            st.push(node->right);
        if(node->left != NULL)
            st.push(node->left);
    }

    for(auto i : preorder)
        cout << i << " ";
}

int main(){
    struct Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);

    root->left->left = new Node(40);
    root->left->right = new Node(60);

    root->right->left = new Node(50);

    preorder(root);
    cout << endl;
    iterative_preorder(root);

    return 0;
}
