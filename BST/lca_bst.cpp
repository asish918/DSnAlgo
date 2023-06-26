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

struct Node* head = NULL;

struct Node* findLCA(struct Node* head, struct Node* p, struct Node* q){
    if(head == NULL) return NULL;
    int curr = head->data;

    if(curr < p->data && curr < q->data)
        return findLCA(head->right, p, q);
    if(curr > p->data && curr > q->data)
        return findLCA(head, p, q);

    return head;
}

int main(){
    head = new Node(6);
    head->left = new Node(2);
    head->right = new Node(8);

    head->left->left = new Node(0);
    head->left->right = new Node(4);

    head->left->right->left = new Node(3);
    head->left->right->right = new Node(5);

    head->right->left = new Node(7);
    head->right->right = new Node(9);

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

    cout << "Common Ancestor - " << endl;
    cout << findLCA(head, head->left, head->right)->data << endl;

    return 0;
}
