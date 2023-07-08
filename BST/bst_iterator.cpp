#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void printTree(Node* root) {
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();

        while(size--) {
            Node* node = q.front();
            q.pop();

            cout << node->data << " ";
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        cout << endl;
    }
    cout << "---------" << endl;
}

class BSTIterator {
    public:
        stack<Node*> st;
        void pushAll(Node* root) {
            while(root) {
                st.push(root);
                root = root->left;
            }
        }

        BSTIterator(Node* root) {
            pushAll(root);
        }

        int next() {
            Node* num = st.top();
            st.pop();
            pushAll(num->right);
            return num->data;
        }

        bool hasNext() {
            return !st.empty();
        }
};

Node* insert(Node*& root, int key) {
    if(root == NULL) {
        Node* new_node = new Node(key);
        return new_node;
    }

    if(key < root->data)
        root->left =insert(root->left, key);
    else if(key > root->data)
        root->right = insert(root->right, key);

    return root;
}

int main() {
    Node* root = NULL;
    root = insert(root, 7);
    root = insert(root, 3);
    root = insert(root, 15);
    root = insert(root, 9);
    root = insert(root, 20);

    printTree(root);

    BSTIterator iter(root);
    cout << iter.next() << endl;
    cout << iter.next() << endl;
    cout << iter.hasNext() << endl;
    cout << iter.next() << endl;
    cout << iter.hasNext() << endl;
    cout << iter.next() << endl;
    cout << iter.hasNext() << endl;
    cout << iter.next() << endl;
    cout << iter.hasNext() << endl;
    return 0; 
}

/*
Brute  force can be imlpemented by simply copying all the contents of tree in a vector thourhg inorder traversal  and then finding next and hasnext in the vector

To imlpement before and hasBefore(), use the same concept but instread of pushing left first, push all right and then the left;

Right - Node - Left
Will give elements in descending order (Reverse Inorder)
*/
