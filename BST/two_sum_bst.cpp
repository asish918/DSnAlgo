#include<iostream>
#include<queue>
#include<vector>
#include<stack>
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

class BSTIterator {
    public:
        stack<Node*> st;
        bool before;
        void pushAll(Node* root) {
            while(root) {
                st.push(root);
                before ? root =root->right : root = root->left;
            }
        }

        BSTIterator(Node* root, bool _before) {
            before = _before;
            pushAll(root);
        }

        int next() {
            Node* node = st.top();
            st.pop();
            before ? pushAll(node->left) : pushAll(node->right);
            return node->data;
        }
};

bool optimal(Node* root, int sum) {
    BSTIterator nextIter(root, false);
    BSTIterator beforeIter(root, true);

    int left = nextIter.next();
    int right = beforeIter.next();

    while(left <= right) {
        if(left + right == sum)
            return true;
        else if(left + right < sum)
            left = nextIter.next();
        else
            right = beforeIter.next();
    }

    return false;
}

void inorder(Node* root, vector<int>& traversal) {
    if(root == NULL)
        return;

    inorder(root->left, traversal);
    traversal.push_back(root->data);
    inorder(root->right, traversal);
}

bool bruteForce(Node* root, int sum) {
    vector<int> traversal;
    inorder(root, traversal);

    int left = 0;
    int right = traversal.size() - 1;

    while(left <= right) {
        if(traversal[left] + traversal[right] == sum)
            return true;
        else if(traversal[left] + traversal[right] > sum)
            right--;
        else 
            left++;
    }

    return false;
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
    cout << "----------" << endl;
}

Node* insert(Node*& root, int key) {
    if(root == NULL)
        return new Node(key);

    if(key < root->data)
        root->left = insert(root->left, key);
    else if(key > root->data)
        root->right = insert(root->right, key);

    return root;
}

int main() {
    Node* root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 7);

    printTree(root);
    cout << bruteForce(root, 9) << endl;
    cout << optimal(root, 9) << endl;
    return 0;
}
