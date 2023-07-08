#include<iostream>
#include<queue>
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

Node* first = NULL;
Node* second = NULL;
Node* prevPointer = NULL;

void findViolations(Node*& root) {
    if(root == NULL)
        return;

    findViolations(root->left);
    if(prevPointer != NULL && root->data < prevPointer->data) {
        if(first == NULL) {
            first = prevPointer;
            second = root;
        }
        else 
            second = root;
    }

    prevPointer = root;
    findViolations(root->right);
}

void correctTree(Node*& root) {
    findViolations(root);

    int temp=first->data;
    first->data=second->data;
    second->data=temp;
}

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
    cout << "--------" << endl;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(8);

    root->left->left = new Node(2);
    root->left->right = new Node(20);

    printTree(root);
    correctTree(root);
    printTree(root);

    cout << first->data << " " << second->data << endl;
    return 0;
}
