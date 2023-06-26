#include <iostream>
#include <algorithm>
using namespace std;

int jump_game_2(int nums[], int n){
    int res = 0;
    int l = 0;
    int r = 0;

    while(r < n - 1){
        int farthest = 0;

        for(int i = l; i<=r; i++)
            farthest = max(farthest, i + nums[i]);

        l = r + 1;
        r = farthest;
        res++;
    }

    return res;
}

int main() {
    int nums[] = {2, 3, 1, 1, 4};
    int n = sizeof(nums)/sizeof(int);

    cout << jump_game_2(nums, n) << endl;

    return 0;
}
