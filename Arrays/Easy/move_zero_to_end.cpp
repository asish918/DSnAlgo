#include<iostream>
#include <vector>
using namespace std;

void bruteForce(vector<int>& arr){
    int n = arr.size();
    vector<int> temp;

    for(int i = 0; i<n; i++)
        if(arr[i] != 0)
            temp.push_back(arr[i]);

    for(int i = 0; i<temp.size(); i++)
        arr[i] = temp[i];

    for(int i = temp.size(); i<n; i++)
        arr[i] = 0;
}

void optimal(vector<int>& arr){

}

int main(){
    vector<int> arr = {3, 5, 0, 0, 4};

    //TC - (O(2n))
    //SC - (O(n))
    bruteForce(arr);

    //TC - (O(n)
    //SC - (O(1)))

    for(int j = 0; j<sizeof(arr) /sizeof(int); j++)
        cout << arr[j] << " ";

    return 0;
}
