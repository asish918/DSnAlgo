#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;


void max_sum_combo(vector<int>& A, vector<int>& B, int N, int K) {
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    priority_queue<pair<int, pair<int, int>>> maxHeap;
    set<pair<int, int>> visited;

    maxHeap.push({A[0] + B[0], {0, 0}});
    visited.insert({0, 0});
    vector<int> ans;

    while(K--) {
        auto element = maxHeap.top();
        maxHeap.pop();

        ans.push_back(element.first);

        int i = element.second.first;
        int j = element.second.second;

        if(i + 1 < N && visited.find({i + 1, j}) == visited.end()) {
            maxHeap.push({A[i + 1] + B[j], {i + 1, j}});
            visited.insert({i + 1, j});
        } 
        
        if(j + 1 < N && visited.find({i, j + 1}) == visited.end()) {
            maxHeap.push({A[i] + B[j + 1], {i, j + 1}});
            visited.insert({i, j + 1});
        }
    }

    for(auto i : ans)
        cout << i << " ";
}

int main() {
    vector<int> A = {1, 4, 2, 3};
    vector<int> B = {2, 5, 1, 6};
    int K = 3;
    int N = A.size();

    max_sum_combo(A, B, N, K);

    return 0;
}

/* 
Sorting in non-increasing order is important because we want to extract the maximum elements from both arrays to form sum combinations later.

we initialize a max heap (priority_queue) to store the sum combinations along with their indices. We use a pair of integers to represent the sum combination, and a pair of integers to represent the indices of the elements in arrays A and B that form the sum. We initialize the max heap with the sum of the largest elements from both arrays (A[0] + B[0]) and insert the corresponding indices {0, 0} into the visitedIndices set to mark them as visited.


We create an empty vector result to store the maximum valid distinct sum combinations. Then, in the while loop, we iterate until K becomes zero or the max heap becomes empty. In each iteration, we extract the top element from the max heap, which is the maximum sum combination. We retrieve the indices of the elements from arrays A and B that form this sum and store them in variables i and j. We add the current sum combination to the result vector and decrement K to track the number of valid combinations remaining.


in each iteration, we check if there are valid indices to explore in both arrays A and B (i.e., i+1 < n and j+1 < m) and if the corresponding indices have not been visited before. If these conditions are met, we calculate the sum of the next elements from arrays A and B based on the current indices and push them into the max heap along with the new indices. We also mark the new indices as visited by inserting them into the visitedIndices set.

Once the while loop finishes, we have found the maximum K valid distinct sum combinations. We return the result vector.

*/
