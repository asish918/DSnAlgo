#include<iostream>
#include<iterator>
#include<map>
#include<vector>
using namespace std;

//O(n * n) Vemry Bad :(
void countFreqNaive(vector<int> arr){
    vector<bool> visited (arr.size(), false);
    int count = 0;

    for(int i = 0; i<arr.size(); i++){
        if(visited[i] == true)
            continue;
        
        count = 1;
        for(int j = i + 1; j<arr.size(); j++){
            if(arr[i] == arr[j]){
                visited[j] = true;
                count++;
            }
        }

        cout << count << " ";
    }
}

//Optimised with Hashing
void countFreqOptimised(vector<int>& arr){
    map<int, int> m;
    int i = 0;

    for(int i = 0; i<arr.size(); i++){
        m[arr[i]]++;
    }

    i = 0;
    for(auto it : m) {
        arr[i] = it.second;
        i++;
    }
}

int main(){
    vector <int> arr;
    arr.push_back(2); 
    arr.push_back(3); 
    arr.push_back(2); 
    arr.push_back(3); 
    arr.push_back(5); 
    // {2, 3, 2, 3, 5};

    // countFreqNaive(arr);
    cout << endl << endl;
    countFreqOptimised(arr);

    for(int i = 0; i<5; i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}