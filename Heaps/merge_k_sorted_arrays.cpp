#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    int row;
    int col;

    Node(int d, int r, int c) {
        data = d;
        row = r;
        col = c;
    }
};

struct Compare {
    bool operator()(const Node* a, const Node* b) const {
        return a->data > b->data;
    }
};

void mergeKSortedArr(int arr[3][3], int k){
    priority_queue<Node*, vector<Node*>, Compare > minHeap;

    for(int i = 0; i<k; i++){
        minHeap.push(new Node(arr[i][0], i, 0));
    }

    vector<int> ans;

    while(!minHeap.empty()) {
        Node* element = minHeap.top();
        minHeap.pop();

        int val = element->data;
        int row = element->row;
        int nextCol = element->col + 1;

        ans.push_back(val);
        
        if(nextCol < k) {
            minHeap.push(new Node(arr[row][nextCol], row, nextCol));
        }
    }

    for(auto i : ans)
        cout << i << " ";
    cout << endl;
}

int main(){
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int k = 3;

    mergeKSortedArr(arr, k);

    return 0;
}

/*
We define a Node class with attributes data, row, and column to represent the elements of the matrix. Each Node object holds the value of an element along with its corresponding row and column indices.

We also define a custom comparator Compare for the Node class. It ensures that the Node objects are sorted based on their data attribute.

The function mergeSortedArrays remains the same, but now it uses the Node class instead of pair<int, int>.

In the mergeSortedArrays function, we create a min heap minHeap using priority_queue with the Node class and the custom Compare comparator.

We iterate over each array in the matrix and push the first element of each array as a Node object into the min heap.

We extract the minimum element from the min heap, which will be the smallest element among the current elements of all arrays.

We add the minimum element to the mergedArray.

We check if there are more elements in the current array. If yes, we create a new Node object with the next element from the same array and push it into the min heap.

We repeat steps 6-8 until the min heap becomes empty.

Finally, we return the mergedArray.
*/
