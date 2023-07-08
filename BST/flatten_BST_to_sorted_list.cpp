#include<iostream>
#include<queue>
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

Node* flatten(struct Node* root){
    struct Node* curr = root;
    Node* head = NULL;
    Node* prev = NULL;

    while(curr != NULL){
        if(curr->left == NULL) {
            if(prev == NULL) {
                prev = curr;
                head = curr;
            }
            else {
                prev->right = curr;
                prev = curr;
            }

            curr = curr->right;
        }
        else {
            Node* leftSubTree = curr->left;

            while(leftSubTree->right && leftSubTree->right != curr)
                leftSubTree = leftSubTree->right;

            if(leftSubTree->right == NULL) {
                leftSubTree->right = curr;
                curr = curr->left;
            }
            else {
                leftSubTree->right = NULL;

                if(prev == NULL) {
                    prev = curr;
                    head = curr;
                }
                else {
                    prev->right = curr;
                    prev = curr;
                }

                curr = curr->right;
            }
        }
    }

    return head;
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
    cout << "-------" << endl;
}
void llTraversal(struct Node* root){
    while(root!= NULL){
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
    cout << "--------" << endl;
}


int main() {
    struct Node* head = new Node(8);
    head->left = new Node(5);
    head->right = new Node(10);

    head->left->left = new Node(2);

    Node* new_head = flatten(head);
    llTraversal(new_head);

    return 0;
}
