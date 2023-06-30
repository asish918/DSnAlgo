#include <iostream>
#include <utility>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

void rankTransform(int arr[], int n){
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;

    for(int i = 0; i<n; i++)
        q.push(make_pair(arr[i], i));

    int currRank = 1, prevEl = -1;
    
    while(!q.empty()){
        auto top = q.top();
        q.pop();
        arr[top.second] = currRank;

        if(prevEl == top.first)
            arr[top.second] = currRank - 1;
        else
            currRank++;

        prevEl = top.first;
    }
}

void anotherApproach(vector<int>& arr, int n) {
    vector<int> sortedArr = arr;

    sort(sortedArr.begin(), sortedArr.end());

    unordered_map<int, int> ranks;

    for(int i = 0; i < n; i++) {
        if(ranks.find(sortedArr[i]) == ranks.end())
            ranks[sortedArr[i]] = i;
    }

    for(int i = 0; i<n; i++)
        arr[i] = ranks[arr[i]] + 1; //Ranks are one index based
}

int main(){
    vector<int> arr = {20, 15, 26, 2, 98, 6};
    int n = arr.size();

    //rankTransform(arr, n);
    anotherApproach(arr, n);

    for(int i = 0; i<n; i++)
        cout << arr[i] << " ";
    return 0;
}

/*
##### Another Approach
Create a copy of the given array arr.

Sort the copy of the array in ascending order. This will help us determine the ranks of the elements.

Create an unordered_map to store the rank of each unique element. The key will be the element, and the value will be its rank.

Iterate over the sorted array and update the ranks in the unordered_map. If an element is encountered for the first time, assign its rank as the current index. If an element is already present in the unordered_map, skip updating its rank.

Iterate over the original array arr. For each element, replace it with its corresponding rank from the unordered_map.

Return the modified array arr with replaced ranks.
*/

/*
#### Heap Approach
The code starts by creating a min heap, q, using the priority_queue container in C++. The min heap stores pairs of integers, where the first element of the pair represents the value of the element, and the second element represents its index in the array.

It then iterates over each element of the array and pushes a pair containing the value of the element and its index into the min heap.

The code initializes two variables, curr and prev. curr represents the current rank, and prev stores the value of the previous element. Both are initially set to different values to ensure the first element is assigned rank 1.

The code enters a loop that continues until the min heap becomes empty.

Inside the loop, it retrieves the top element from the min heap using q.top(). The top element is the pair with the smallest value.

It pops the top element from the min heap using q.pop().

The code assigns the current rank, curr, to the element at the index specified by top.second in the original array. This replaces the original value with its rank.

The code checks if the previous element, prev, is equal to the current element's value. If they are the same, it means the current element is a duplicate.

If the current element is a duplicate, it assigns the rank curr - 1 to the element in the original array. This ensures that all duplicate elements have the same rank as the first occurrence.

If the current element is not a duplicate, it increments the current rank by one, curr++, to assign a new rank.

The code updates the value of prev to store the value of the current element for the next iteration.

The loop continues until all elements have been processed, and the min heap becomes empty.

After the loop, the array arr contains the modified ranks of the elements.
*/
