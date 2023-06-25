#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generatePerumations1(vector<int> arr, int freq_map[], vector<int>& ds){
    if(ds.size() == arr.size()){
        for(auto it : ds)
            cout << it << " ";
        cout << endl;

        return;
    }

    for(int i = 0; i<arr.size(); i++){
        //For generating unique permutations
        //if(arr[i] == arr[i - 1] && !freq_map[i - 1]) continue;

        if(!freq_map[i]){
            ds.push_back(arr[i]);
            freq_map[i] = 1;
            generatePerumations1(arr, freq_map, ds);
            ds.pop_back();
            freq_map[i] = 0;
        }
    }
}

void generatePerumations2(int index, vector<int>& arr) {
    if(index == arr.size() - 1){
        for(auto it : arr)
            cout << it << " ";
        cout << endl;

        return;
    }

    for(int i = index; i<arr.size(); i++){
        //For generatine unique permutations we have to use a set
        //No other way

        swap(arr[index], arr[i]);
        generatePerumations2(index + 1, arr);
        swap(arr[index], arr[i]);
    }
}

int main() {
    vector<int> arr = {1, 1, 2};
    //int freq_map[arr.size()] = {0};
    //vector<int> ds;

    //generatePerumations1(arr, freq_map, ds);
    generatePerumations2(0, arr);
    return 0;
}
