#include <iostream>
#include <vector>
#include <array>
using namespace std;

int merge(vector<int>& arr, int start, int mid, int end){
    int count = 0;
    int left = start;
    int right = mid + 1;
    vector<int> temp;

    while(left <= mid && right <= end){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            count += (mid - left + 1);
            right++;
        }
    }

    while(left <= mid)
        temp.push_back(arr[left++]);

    while(right <= end)
        temp.push_back(arr[right++]);

    for(int i = start; i<=end; i++)
        arr[i] = temp[i - start];

    return count;
}

int mergeSort(vector<int>& arr, int start, int end){
    int count = 0;

    if(start >= end)
        return count;

    int mid = (end - start)/2 + start;
    count += mergeSort(arr, start, mid);
    count += mergeSort(arr, mid + 1, end);
    count += merge(arr, start, mid, end);
    
    return count;
}

int bruteForce(vector<int> arr){
    int count = 0;

    for(int i = 0; i<arr.size(); i++){
        for(int j = i + 1; j<arr.size(); j++){
            if(arr[i] > arr[j])
                count++;
        }
    }

    return count;
}

int main(){
    vector<int> arr = {2, 4, 1, 3, 5};
    int n = arr.size();

    //Brute Force O(n^2)
    //cout << bruteForce(arr) << endl;

    //Optimal Approach O(nlogn)
    cout << mergeSort(arr, 0, n - 1) << endl;

    return 0;
}
