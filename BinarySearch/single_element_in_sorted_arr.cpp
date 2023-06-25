#include<iostream>
#include<vector>
using namespace std;

int main(){
    int nums[] = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    int n = sizeof(nums)/sizeof(int);

    int low = 0;
    int high = n - 1;

    while(low < high) {
        int mid = (high - low)/2 + low;
        int next_mid = mid % 2 == 0 ? mid + 1 : mid - 1;
        if(nums[mid] == nums[next_mid]) low = mid + 1;
        else high = mid;;
    }

    cout << nums[low] << endl;

    return 0;
}
