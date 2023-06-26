#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
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

int widthOfTree(struct Node* root){
    if(!root)
        return 0;

    int ans = 0;
    queue<pair<struct Node*, int> > q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        int min = q.front().second;
        int size = q.size();
        int first, last;

        for(int i = 0; i<size; i++){
            struct Node* node = q.front().first;
            int cur_id = q.front().second - min;

            q.pop();
            if(i == 0) first = cur_id;
            if(i == size - 1) last = cur_id;

            if(node->left)
                q.push(make_pair(node->left, 2*cur_id+1));
            if(node->right)
                q.push(make_pair(node->right, 2*cur_id+2));
        }

        ans = max(ans, last - first + 1);
    }

    return ans;
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);

    root->left->right = new Node(3);
    root->left->left = new Node(5);

    root->right->right = new Node(9);

    cout << widthOfTree(root) << endl;
    return 0;
}
