#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    public:
    vector<int> heap;
    
    int parent(int i) {return (i - 1) / 2;};
    int rightChild(int i) {return 2*i + 2;};
    int leftChild(int i) {return 2*i + 1;};

    void heapifyUp(int i) {
        if(i != 0 && heap[i] > heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);
            heapifyUp(parent(i));
        }
    }

    void heapifyDown(int i) {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if(left < heap.size() && heap[largest] < heap[left])
            largest = left;
        if(right < heap.size() && heap[largest] < heap[right])
            largest = right;

        if(largest != i) {
            swap(heap[largest], heap[i]);
            heapifyDown(largest);
        }
    }

    void insert(int i) {
        heap.push_back(i);
        int index = heap.size() - 1;
        heapifyUp(index);
    }

    int extractMax(int i) {
        if(heap.empty())
            return -1;

        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return max;
    }

    int getMax() {
        if(heap.empty())
            return -1;

        return heap[0];
    }
};

int main () {
    MaxHeap maxHeap;

    maxHeap.insert(9);
    maxHeap.insert(3);
    maxHeap.insert(5);
    maxHeap.insert(1);
    maxHeap.insert(4);
    maxHeap.insert(2);
    
    cout << maxHeap.getMax() << endl;
    
    return 0;
}
