#include<iostream>
#include<stack>
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

struct Node* prev = NULL;
stack<Node*> st;

void flattenIterative(struct Node* root){
    st.push(root);

    while(!st.empty()){
        struct Node* curr = st.top();
        st.pop();

        if(curr->right)
            st.push(curr->right);
        if(curr->left)
            st.push(curr->left);
        if(!st.empty())
            curr->right = st.top();
        curr->left = NULL;
    }
}

void flattenRecursive(struct Node* root){
    if(root == NULL)
        return;

    flattenRecursive(root->right);
    flattenRecursive(root->left);

    //root->right = prev;
    root->left = NULL;

    //prev = root;
}

void flattenOptimised(struct Node* root){
    struct Node* curr = root;
    while(curr != NULL){
        if(curr->left != NULL){
            struct Node* prev = curr->left;

            while(prev->right != NULL)
                prev = prev->right;
        
            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

void llTraversal(struct Node* root){
    while(root->right != NULL){
        cout << root->data << " ";
        root = root->right;
    }
}

int main() {
    struct Node* head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(5);

    head->left->left = new Node(3);
    head->left->right = new Node(4);

    head->right = new Node(5);
    head->right->right = new Node(6);

    //flattenRecursive(head);
    //flattenIterative(head);
    flattenOptimised(head);
    llTraversal(head);

    return 0;
}
