#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <map>
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

void topView(struct Node* root){
    queue<pair<Node*, int> > q;
    map<int, int> mpp;

    q.push(make_pair(root, 0));
    
    while(!q.empty()){
        auto it = q.front();
        q.pop();

        Node* node = it.first;
        int level = it.second;

        if(mpp.find(level) == mpp.end()) mpp[level] = node->data;

        if(node->left != NULL)
            q.push(make_pair(node->left, level - 1));
        if(node->right != NULL)
            q.push(make_pair(node->right, level + 1));
    }

    for(auto it : mpp)
        cout << it.second << endl;
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    //root->left->right = new Node(5);

    topView(root);

    return 0;
}
