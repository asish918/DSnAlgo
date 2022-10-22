#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int main(){
    int arr[] = {2, 6, 1, 9, 4, 5, 3};
    int n = sizeof(arr) / sizeof(int);
    int i = 0;

    set<int> hashSet;

    for(i = 0; i<n; i++){
        hashSet.insert(arr[i]);
    }

    int longestStreak = 0;

    for(i = 0; i<n; i++){
        if(!hashSet.count(arr[i] - 1)) {
            int currentNum = arr[i];
            int currentStreak = 1;

            while(hashSet.count(currentNum+1)){
                currentNum+=1;
                currentStreak+=1;
            }

            longestStreak = max(longestStreak, currentStreak);
        }
    }

    cout << longestStreak << endl;
    
    return 0;
}