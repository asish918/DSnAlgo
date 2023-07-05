#include <iostream>
#include <unordered_map>
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

void markParent(struct Node* root, unordered_map<Node*, Node*>& parent_track){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        struct Node* current = q.front();
        q.pop();

        if(current->left){
            parent_track[current->left] = current;
            q.push(current->left);
        }
        if(current->right){
            parent_track[current->right] = current;
            q.push(current->right);
        }
    }
}

void distanceK(struct Node* root, struct Node* target, int K){
    unordered_map<Node*, Node*> parent_track;

    markParent(root, parent_track);

    queue<Node*> q;
    unordered_map<Node*, bool> visited;
    q.push(target);
    visited[target] = true;
    int curr_level = 0;

    while(!q.empty()){
        int size = q.size();

        if(curr_level++ == K) break;

        for(int i = 0; i<size; i++){
            struct Node* current = q.front();
            q.pop();
            if(current->left && !visited[current->left]){
                q.push(current->left);
                visited[current->left] = true;
            }
            if(current->right && !visited[current->right]){
                q.push(current->right);
                visited[current->right] = true;
        }
            if(parent_track[current] && !visited[parent_track[current]]){
                q.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }

    while(!q.empty()){
        cout << q.front()->data << " ";
        q.pop();
    }
}

int main(){
    struct Node* target;
    struct Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);

    target = root->left;

    root->left->right = new Node(2);
    root->left->left = new Node(6);

    root->right->left = new Node(0);
    root->right->right = new Node(8);

    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    distanceK(root, target, 2);

    return 0;
}

/*
### Incase Reference to target node is not given

void markParents(Node* root, Node*& target_node, int target, unordered_map<Node*, Node*>& parent_track) {
    if(root == NULL)
        return;

    if(root->data == target)
        target_node = root;

    if(root->left) parent_track[root->left] = root;
    if(root->right) parent_track[root->right] = root;

    markParents(root->left, target_node, target, parent_track);
    markParents(root->right, target_node, target, parent_track);
}

void nodesAtK(Node* root, int target, int K, vector<int>& ans) {
    unordered_map<Node*, Node*> parent_track;
    unordered_map<Node*, bool> visited;
    Node* target_node = NULL;
    
    markParents(root, target_node, target, parent_track);

    queue<Node*> q;
    q.push(target_node);
    visited[target_node] = true;
    int curr_level = 0;

    while(!q.empty()) {
        int size = q.size();
        if(curr_level++ == K) break;

        while(size--) {
            Node* node = q.front();
            q.pop();

            if(node->left && !visited[node->left]) {
                q.push(node->left);
                visited[node->left] = true;
            }

            if(node->right && !visited[node->right]) {
                q.push(node->right);
                visited[node->right] = true;
            }

            if(parent_track[node] && !visited[parent_track[node]]) {
                q.push(parent_track[node]);
                visited[parent_track[node]] = true;
            }
        }
    }

    while(!q.empty()) {
        ans.push_back(q.front()->data);
        q.pop();
    }
}
*/
