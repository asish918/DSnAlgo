#include <iostream>
#include<map>
using namespace std;

// Scanning entire array for each element 
// Time Complexity - O(n^2)
// Space Complexity - O(1)
int bruteForce(int arr[], int n){
    for(int i = 0; i<n; i++){
        int count = 0;
        for(int j = 0; j<n; j++)
            if(arr[j] == arr[i])
                count++;
        if(count > n/2)
            return arr[i];
    }
    return -1;
}

// Better Approach using Hashing
// Time Complexity - O(nlogn) + O(n)
// Space Complexity - O(n) 
int betterApproach(int arr[], int n){
    map<int, int> mpp;

    for(int i = 0; i<n; i++)
        mpp[arr[i]]++;

    for(auto it : mpp)
        if(it.second > n/2)
            return it.first;
    return -1;
}

//Moore's Voting Algorithm
//Time Complexity - O(n) + O(n)
//Space Complexity - O(1)
int optimalApproach(int arr[], int n){
    int element = 0;
    int count = 0;

    for(int i = 0; i<n; i++){
        if(count == 0){
            element = arr[i];
            count++;
        }
        else if(arr[i] == element)
            count++;
        else
            count--;
    }

    int verifyCount = 0;
    for(int i = 0; i<n; i++)
        if(arr[i] == element)
            verifyCount++;

    if(verifyCount > n/2)
        return element;
    return -1;
}

int main()
{
    int arr[] = {3, 1, 3, 3, 2};
    int N = 5;

    cout << bruteForce(arr, N) << endl;
    cout << betterApproach(arr, N) << endl;
    cout << optimalApproach(arr, N) << endl;
    return 0;
}
