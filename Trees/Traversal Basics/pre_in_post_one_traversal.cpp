#include <iostream>
#include <vector>
#include <stack>
#include <utility>
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

void preInPost(struct Node* root){
    vector<int> pre, in, post;
    stack<pair<Node*, int> > st;

    st.push(make_pair(root, 1));

    while(!st.empty()){
        auto it = st.top();
        st.pop();

        if(it.second == 1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->left != NULL)
                st.push(make_pair(it.first->left, 1));
        }

        else if(it.second == 2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->right != NULL)
                st.push(make_pair(it.first->right, 1));
        }

        else 
            post.push_back(it.first->data);
    }

    cout << "Preorder - ";
    for(auto i : pre)
        cout << i << " ";
    cout << endl;
    cout << "Inorder - ";
    for(auto i : in)
        cout << i << " ";
    cout << endl;
    cout <<  "Postorder - ";
    for(auto i : post)
        cout << i << " ";
    cout << endl;
}


int main(){
    struct Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);

    root->left->left = new Node(40);
    root->left->right = new Node(60);

    root->right->left = new Node(50);


    preInPost(root);
    return 0;
}
