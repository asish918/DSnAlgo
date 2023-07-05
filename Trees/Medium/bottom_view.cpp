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

void bottomView(struct Node* root){
    queue<pair<Node*, int> > q;
    map<int, int> mpp;

    q.push(make_pair(root, 0));
    
    while(!q.empty()){
        auto it = q.front();
        q.pop();

        Node* node = it.first;
        int level = it.second;

        mpp[level] = node->data;

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
    root->left = new Node(3);
    root->right = new Node(2);

    //root->left->right = new Node(5);

    bottomView(root);

    return 0;
}
/// code for recrsive approach,just keep track of row number.
//Structur of map: colum_no={data,rownumber}
//if row number is larger than previous stored data,then replace.

void f(BinaryTreeNode<int> * root, int row,int col,map<int,pair<int,int>> &mp){
    if(root==0)return;



   if(row>=mp[col].second)
   mp[col]={root->data,row};



    f(root->left,row+1,col-1,mp);
    f(root->right,row+1,col+1,mp);

}*

*/
