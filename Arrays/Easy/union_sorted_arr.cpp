#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int arr2[] = {1, 3, 5, 7};
    vector<int> new_arr;

    int index1 = 0, index2 = 0;
    int m = sizeof(arr1) / sizeof(int);
    int n = sizeof(arr2) / sizeof(int);


    // Noob approach
    // while (index1 < m && index2 < n)
    // {
    //     if(arr1[index1] == arr2[index2]){
    //         new_arr.push_back(arr1[index1]);
    //         index1++;
    //         index2++;
    //     }

    //    else if(arr1[index1] > arr2[index2]) {
    //         new_arr.push_back(arr2[index2]);
    //         index2++;
    //     }

    //     else {
    //         new_arr.push_back(arr1[index1]);
    //         index1++;
    //     }
    // }

    // while(index1 < m) {
    //         new_arr.push_back(arr1[index1]);
    //         index1++;
    // }

    // while(index2 < n) {
    //         new_arr.push_back(arr2[index2]);
    //         index2++;
    // }

    // Optimised
    set<int> union_arr;
    for(int i = 0; i<m; i++){
        union_arr.insert(arr1[i]);
    }

    for(int j = 0; j<n; j++){
        union_arr.insert(arr2[j]);
    }

    for(auto v : union_arr){
        new_arr.push_back(v);
    }
    
    for(int i = 0; i<new_arr.size(); i++){
        cout << new_arr[i] << " ";
    }
    
    return 0;
}