#include<iostream>
#include<queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

struct Node* findLast(struct Node* head){
    while(head->right != NULL)
        head = head->right;

    return head;
}

struct Node* helper(struct Node* head){
    if(head->left == NULL)
        return head->right;
    
    else if(head->right == NULL)
        return head->left;

    struct Node* rightChild = head->right;
    struct Node* lastLeftChild = findLast(head->left);
    lastLeftChild->right = rightChild;

    return head->left;
}

struct Node* deleteNode(struct Node* head, int val){
    if(!head)
        return head;

    if(head->data == val)
        return helper(head);

    struct Node* dummy = head;
    
    while(head != NULL){
        if(val < head->data){
            if(head->left != NULL && head->left->data == val){
                head->left = helper(head->left);
                break;
            }
            else 
                head = head->left;
        }
        else {
            if(head->right != NULL && head->right->data == val){
                head->right = helper(head->right);
                break;
            }
            else
                head = head->right;
        }
    }

    return dummy;
}

struct Node* head = NULL;

int main(){
    head = new Node(5);
    head->left = new Node(3);
    head->right = new Node(6);

    head->left->left = new Node(2);
    head->left->right = new Node(4);

    head->right->right = new Node(7);

    head = deleteNode(head, 3);

    queue<Node*> q;
    q.push(head);

    while(!q.empty()){
        int size = q.size();

        for(int i = 0; i<size; i++){
            struct Node* node = q.front();
            q.pop();

            cout << node->data << " ";

            if(node->left != NULL)
                q.push(node->left);

            if(node->right != NULL)
                q.push(node->right);
        }
        cout << endl;
    }

    return 0;
}
