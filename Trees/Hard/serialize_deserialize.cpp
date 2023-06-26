#include <iostream>
#include <queue>
#include <sstream>
#include <string>
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

void levelOrder(struct Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        struct Node* node = q.front();
        q.pop();

        cout << node->data << " ";
        if(node->left)
            q.push(node->left);
        if(node->right)
            q.push(node->right);
    }
}

void deserialize(string data){
    stringstream s(data); 
    string str;
    getline(s, str, ',');
    struct Node* root = new Node(stoi(str));
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
       struct Node* node = q.front();
       q.pop();

       getline(s, str, ',');
       if(str == "#")
           node->left = NULL;
       else {
           struct Node* leftNode = new Node(stoi(str));
           node->left = leftNode;
           q.push(leftNode);
       }

       getline(s, str, ',');
       if(str == "#")
            node->right = NULL;
       else {
           struct Node* rightNode = new Node(stoi(str));
           node->right = rightNode;
           q.push(rightNode);
       }
    }

    levelOrder(root);
}

void serialize(struct Node* root){
    string s = "";
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        struct Node* node = q.front();
        q.pop();

        if(node == NULL) s.append("#,");
        else
            s.append(to_string(node->data) + ',');
        
        if(node != NULL){
            q.push(node->left);
            q.push(node->right);
        }
    }

    cout << s << endl;
    deserialize(s);
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->right->right = new Node(5);
    root->right->left = new Node(4);

    serialize(root);

    return 0;
}
