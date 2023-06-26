#include <iostream>
#include <queue>
#include <set>
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

void verticalTraversal(struct Node* root){
    map<int, map<int, multiset<int> > > nodes;
    queue<pair<Node*, pair<int, int> > > q;
    q.push(make_pair(root, make_pair(0, 0)));

    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node* node = it.first;
        int x = it.second.first, y = it.second.second;
        nodes[x][y].insert(node->data);
        if(node->left != NULL)
            q.push(make_pair(node->left, make_pair(x - 1, y + 1)));
        if(node->right != NULL)
            q.push(make_pair(node->right, make_pair(x + 1, y + 1)));
    }

    for(auto i : nodes){
        for(auto j : i.second){
             for(auto m : j.second)
                 cout << m << " ";
        }
        cout << endl;
    }
}

int main(){
    struct Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);

    root->right->right = new Node(7);
    root->right->left = new Node(15);

    verticalTraversal(root);

    return 0;
}
