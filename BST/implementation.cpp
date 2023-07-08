#include <iostream>
#include<queue>
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

//Recursive
Node* insertRecursive(Node*& root, int key) {
    if(root == NULL) {
        Node* new_node = new Node(key);
        return new_node;
    }

    if(key < root->data)
        root->left = insertRecursive(root->left, key);
    else if(key > root->data)
        root->right = insertRecursive(root->right, key);

    return root;
}

//Iterative
void insertIterative(Node*& root, int key) {
    Node* temp = root;
    Node* prev = NULL;

    if(root == NULL) {
        root = new Node(key);
        return;
    }

    while(temp) {
        if(key < temp->data) {
            prev = temp;
            temp = temp->left;
        }
        else if(key > temp->data) {
            prev = temp;
            temp = temp->right;
        }
    }

    if(prev->data > key)
        prev->left = new Node(key);
    else if(prev->data < key)
        prev->right = new Node(key);
}

void levelOrder(Node* root) {
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
}

int main(){
    //Node* root = NULL;
    //insertIterative(root, 3);
    //insertIterative(root, 2); 
    //insertIterative(root, 1);
    //insertIterative(root, 4); 
    //insertIterative(root, 5);
    
    Node* root1 = NULL;
    root1 = insertRecursive(root1, 3);
    root1 = insertRecursive(root1, 2); 
    root1 = insertRecursive(root1, 1);
    root1 = insertRecursive(root1, 4); 
    root1 = insertRecursive(root1, 5);
    levelOrder(root1);
    return 0;
}
