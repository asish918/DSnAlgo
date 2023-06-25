#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void direct(vector<int>& arr){
    next_permutation(arr.begin(), arr.end());

    for(auto i :  arr)
        cout << i << " ";
    cout << endl;
}

void full_implentation(vector<int> arr){
    int index = -1;
    int n = arr.size();

    for(int i = n - 2; i>=0; i--){
        if(arr[i] < arr[i+1]){
            index = i;
            break;
        }
    }

    if(index == -1){
        reverse(arr.begin(), arr.end());

        for(auto i : arr)
            cout << i << " ";
        cout << endl;
        return;
    }
        
    for(int i = n - 1; i>index; i--){
        if(arr[i] > arr[index]){
            swap(arr[i], arr[index]);
            break;
        }
    }
    reverse(arr.begin() + index + 1, arr.end());
    for(auto i : arr)
        cout << i << " ";
    cout << endl;

}

int main() {
    vector<int> arr = {1, 2, 3, 6, 5, 4};
    
    //Optimal but too direct
    //direct(arr);

    //Full implementation
    full_implentation(arr);
    return 0;
}
