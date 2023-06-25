#include <iostream>
#include <vector>
using namespace std;

int bruteForce(vector<int> arr){
    int n = arr.size();
    int count = 0;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(arr[i] > 2*arr[j])
                count++;
        }
    }

    return count;
}

void merge(vector<int>& arr, int start, int mid, int end){
    int left = start;
    int right = mid + 1;
    vector<int> temp;

    while(left <= mid && right <= end){
        if(arr[left] <= arr[right])
            temp.push_back(arr[left++]);
        else
         temp.push_back(arr[right++]);
    }

    while(left <= mid)
        temp.push_back(arr[left++]);
    
    while(right <= end)
        temp.push_back(arr[right++]);

    for(int i = start; i<=end; i++)
        arr[i] = temp[i - start];
}

int findCount(vector<int> arr, int start, int mid, int end){
    int count = 0;
    int right = mid + 1;

    for(int i = start; i<=mid; i++){
        while(right <= end && arr[i] > 2*arr[right])
            right++;
        
        count += (right - (mid + 1));
    }
    return count;
}

int mergeSort(vector<int>& arr, int start, int end){
    int count = 0;

    if(start >= end)
        return count;

    int mid = (end - start)/2 + start;

    count += mergeSort(arr, start, mid);
    count += mergeSort(arr, mid+1, end);
    count += findCount(arr, start, mid, end);
    merge(arr, start, mid, end);

    return count;
}

int main() {
    vector<int> arr = {3, 2, 4, 5, 1, 20};
    
    //Brute Force O(n^2)
    //cout << bruteForce(arr) << endl;

    //Optimal O(2nlogn)
    cout << mergeSort(arr, 0, arr.size() - 1) << endl;
    return 0;
}
