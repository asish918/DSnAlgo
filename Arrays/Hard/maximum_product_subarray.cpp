#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

int bruteForce(vector<int> arr){
    int n = arr.size();

    int max_prod = INT_MIN;

    for(int i = 0; i<n; i++){
        int ans = 1;

        for(int j = i; j<n; j++){
            ans*=arr[j];
            max_prod = max(ans, max_prod);

        }
    }

    return max_prod;
}

int optimal(vector<int> arr){
    int max_prod = INT_MIN;
    int prefix = 1, suffix = 1;

    for(int i = 0; i<arr.size(); i++){
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;

        prefix = prefix * arr[i];
        suffix = suffix * arr[arr.size()-i-1];
        max_prod = max(max_prod, max(prefix, suffix));
    }

    return max_prod;
}

int main(){
    vector<int> arr = {6, -3, -10, 0, 2};

    //Brute Force (O(n^2))
    //cout << bruteForce(arr) << endl;
    
    //Optimal (O(n))
    cout << optimal(arr) << endl;

    return 0;
}
