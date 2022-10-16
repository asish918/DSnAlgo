#include<iostream>
#include<vector>
using namespace std;

int main(){
    int arr[] = {2, 1};
    int N = 3;
    int missing_no = 0;

    // Noob approach O(n) space complexity
    vector<int> subs_arr (N, 0);

    for(int i = 0; i<sizeof(arr) / sizeof(int); i++){
        subs_arr[arr[i]]++;
    }

    for(int j = 1; j<=subs_arr.size(); j++){
        if(subs_arr[j] == 0)
            missing_no = j; 
    }

    // Gauss Formula

    int sum = 0;
    int total = (N * (N+1)) / 2;
    for(int k = 0; k<N-1; k++)
        sum+=arr[k];
    
    missing_no = total - sum;

    cout << missing_no << endl;
    
    return 0;
}