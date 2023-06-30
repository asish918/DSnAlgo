#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void sortArrayWithKDistance(int arr[], int n, int k) {
    //Using Min-Heap

    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> sortedArray(n);

    for(int i = 0; i<=k; i++) 
        minHeap.push(arr[i]);

    int index = 0;

    for(int i = k + 1; i<n; i++) {
        sortedArray[index++] = minHeap.top();
        minHeap.pop();

        minHeap.push(arr[i]);
    }

    while(!minHeap.empty()) {
        sortedArray[index++] = minHeap.top();
        minHeap.pop();
    }

    for(auto i : sortedArray)
        cout << i << " ";
    cout << endl;
}

int main() {
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int n = sizeof(arr) / sizeof(int);
    int k = 3;
    
    sortArrayWithKDistance(arr, n, k);
    return 0;
}

/*
The function sortArrayWithKDistance takes an array arr and an integer k as input.
We create an empty vector sortedArray of the same size as arr to store the sorted array.
We create a min-heap (priority_queue) named minHeap to keep track of the smallest k+1 elements at any given time.
We insert the first k+1 elements of arr into the min-heap.
We initialize an index variable to keep track of the position in sortedArray where we will insert the next element.
We process the remaining elements of arr starting from index k+1.
For each element at index i, we extract the minimum element from the min-heap (which will always be the smallest element within the range of k+1 elements).
We insert the extracted minimum element into sortedArray at position index.
We push the current element at index i into the min-heap.
We repeat steps 7-9 until we have processed all elements from arr.
After processing all elements, we still have k elements remaining in the min-heap. We extract each remaining element and insert it into sortedArray at position index.
Finally, we return the sortedArray.
The printArray function is used to print the elements of the sorted array.
*/
