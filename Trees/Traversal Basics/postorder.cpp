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

void postorder(struct Node* root){
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void iterative_postOrder_2stack(struct Node* root){
    vector<int> postorder;
    stack<Node*> st1, st2;
    st1.push(root);
    
    while(!st1.empty()){
        root = st1.top();
        st1.pop();

        st2.push(root);
        if(root->left != NULL)
            st1.push(root->left);
        if(root->right != NULL)
            st1.push(root->right);
    }

    while(!st2.empty()){
        postorder.push_back(st2.top()->data);
        st2.pop();
    }

    for(auto i : postorder)
        cout << i << " ";
}

void iterative_postOrder_1stack(struct Node* root){
    vector<int> postorder;
    stack<Node*> st;

    st.push(root);
    Node* curr = root;

    while(!st.empty() || curr != NULL){
        if(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        else {
            Node* temp = st.top()->right;
            if(temp == NULL){
                temp = st.top();
                st.pop();
                postorder.push_back(temp->data);

                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            }
            else
                curr = temp;
        }
    }

    for(auto i : postorder)
        cout << i <<  " ";
}
int main(){
    struct Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);

    root->left->left = new Node(40);
    root->left->right = new Node(60);

    root->right->left = new Node(50);

    postorder(root);
    cout << endl;
    iterative_postOrder_2stack(root);
    cout << endl;
    iterative_postOrder_1stack(root);

    return 0;
}
