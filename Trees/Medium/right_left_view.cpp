#include <iostream>
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

void leftView(struct Node* root, int level, vector<int>& res){
    if(root == NULL)
        return;

    if(level == res.size())
        res.push_back(root->data);

    leftView(root->left, level + 1, res);
    leftView(root->right, level + 1, res);
}

void rightView(struct Node* root, int level, vector<int>& res){
    if(root == NULL)
        return;

    if(level == res.size())
        res.push_back(root->data);

    rightView(root->right, level + 1, res);
    rightView(root->left, level + 1, res);
}

void sideView(struct Node* root){
    vector<int> left_ans;
    vector<int> right_ans;

    leftView(root, 0, left_ans);
    rightView(root, 0, right_ans);

    cout << "Left view - \n";
    for(auto i : left_ans)
        cout << i << " ";

    cout << "\nRight view - \n";
    for(auto i : right_ans)
        cout << i << " ";
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(5);
    root->right->right = new Node(4);

    sideView(root);
    return 0;
}
