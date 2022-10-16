#include<iostream>
#include<vector>
using namespace std;

int main(){
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int arr2[] = {1, 3, 5, 7};
    vector<int> new_arr;

    int index1 = 0, index2 = 0;
    int m = sizeof(arr1) / sizeof(int);
    int n = sizeof(arr2) / sizeof(int);

    while(index1 < m && index2 < n) {
        if(arr1[index1] < arr2[index2]) {
            index1++;
        }
        
        else if(arr1[index1] > arr2[index2]) {
            index2++;
        }

        else {
            new_arr.push_back(arr2[index2]);
            index1++;
            index2++;
        }
    }

    for(int i = 0; i<new_arr.size(); i++){
        cout << new_arr[i] << " ";
    }

    return 0;
}