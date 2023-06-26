#include<iostream>
#include<unordered_map>
using namespace std;

class LRUCache
{
    public:
    //Constructor for initializing the cache capacity with the given value.
        struct Node {
            int key;
            int val;
            Node* next;
            Node* prev;

            Node(int _key, int _val) {
                key = _key;
                val = _val;
            }
        };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int capacity;
    unordered_map<int, Node*> mpp;

    LRUCache(int cap)
    {
        capacity = cap;
        head->prev = NULL;
        head->next = tail;
        tail->prev = head;
        tail->next = NULL;
    }

    //Function to return value corresponding to the key.
    void deleteNode(struct Node* del) {
        Node* delprev = del->prev;
        Node* delnext = del->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    void insertNode(struct Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        temp->prev = newNode;
        head->next = newNode;
        newNode->prev = head;
    }

    int GET(int key)
    {
        if(mpp.find(key) != mpp.end()) {
            Node* resnode = mpp[key];
            int val = resnode->val;
            mpp.erase(key);
            deleteNode(resnode);
            insertNode(resnode);
            mpp[key] = head->next;
            return val;
        }

        return -1;
    }

    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        if(mpp.find(key) != mpp.end()) {
            Node* resnode = mpp[key];
            deleteNode(resnode);
            mpp.erase(key);
        }
        if(mpp.size() == capacity) {
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        Node* newNode = new Node(key, value);
        insertNode(newNode);
        mpp[key] = newNode;
    }
};

int main() {
    LRUCache* cache = new LRUCache(2);

    cache->SET(1, 2);
    cache->SET(2, 3);
    cache->SET(1, 5);
    cache->SET(4, 5);
    cache->SET(6, 7);

    cout << cache->GET(4) << endl;
    cache->SET(1, 2);
    cout << cache->GET(3) << endl;

    return 0;
}
