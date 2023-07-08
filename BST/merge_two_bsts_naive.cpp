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

void traversal(Node* root, vector<int>& inorder) {
    if(root == NULL)
        return;

    traversal(root->left, inorder);
    inorder.push_back(root->data);
    traversal(root->right, inorder);
}

vector<int> mergeTraversals(vector<int> arr1, vector<int> arr2) {
    int n = arr1.size();
    int m = arr2.size();

    vector<int> ans;

    int i = 0, j = 0;
    while(i < n && j < n) {
        if(arr1[i] <= arr2[j]){
            ans.push_back(arr1[i]);
            i++;
        }
        else {
            ans.push_back(arr2[j]);
            j++;
        }
    }

    while(i < n) {
        ans.push_back(arr1[i]);
        i++;
    }

    while(j < m) {
        ans.push_back(arr2[j]);
        j++;
    }

    return ans;
}

Node* buildTree(vector<int> merged, int left, int right) {
    if(left > right)
        return NULL;
    
    int mid = (right - left)/2 + left;
    Node* root = new Node(merged[mid]);

    root->left = buildTree(merged, left, mid - 1);
    root->right = buildTree(merged, mid + 1, right);

    return root;
}

Node* mergeBSTs(Node* root1, Node* root2) {
    vector<int> inorder1;
    vector<int> inorder2;

    traversal(root1, inorder1);
    traversal(root2, inorder2);

    vector<int> merged = mergeTraversals(inorder1, inorder2);

    Node* new_root = buildTree(merged, 0, merged.size() - 1);

    return new_root;
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

int main() {
    Node* root1 = new Node(12);
    root1->left = new Node(9);
    root1->left->left = new Node(6);
    root1->left->right = new Node(11);

    Node* root2 = new Node(8);
    root2->left = new Node(5);
    root2->right = new Node(10);
    root2->left->left = new Node(2);

    printTree(root1);
    printTree(root2);

   printTree(mergeBSTs(root1, root2));

    return 0;
}
