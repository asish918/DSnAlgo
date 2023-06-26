#include <iostream>
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

bool checkSame(struct Node* p, struct Node* q){
    if(p == NULL || q == NULL)
        return (p==q);

    return (p->data==q->data) && checkSame(p->left, q->left) && checkSame(p->right, q->right);
}

int main(){
    struct Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    root1->left->right = new Node(5);


    struct Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    root2->left->right = new Node(5);

    cout << checkSame(root1, root2);

    return 0;
}
