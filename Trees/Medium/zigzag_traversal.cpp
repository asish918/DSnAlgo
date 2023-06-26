#include <iostream>
#include <queue>
#include <vector>
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

void zigzagTraversal(struct Node* root){
    vector<vector<int> > ans;
    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> row(size);

        for(int i = 0; i<size; i++){
            Node* node = q.front();
            q.pop();

            int index = leftToRight ? i : (size - 1 - i);

            row[index] = node->data;

            if(node->left != NULL)
                q.push(node->left);
            if(node->right != NULL)
                q.push(node->right);
        }

        leftToRight = !leftToRight;
        ans.push_back(row);
    }

    for(auto i : ans){
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }
}
int main(){
    struct Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);

    root->right->right = new Node(7);
    root->right->left = new Node(15);

    zigzagTraversal(root);
    return 0;
}
