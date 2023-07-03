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

        //This check is for the condition when reaching the end is not guaranteed and we need to return -1 in that case
        //if(r == farthest) 
        //    return -1;
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

/*
Initialize res to 0, which represents the minimum number of jumps required.
Initialize l and r to 0, which represent the current left and right boundaries of the reachable indices.
Get the size of the input vector nums and store it in n.
Enter a while loop that continues until the right boundary r is less than the last index (n - 1).
Inside the loop, initialize farthest to 0, which will store the index that can be reached with the farthest jump from the current reachable indices.
Iterate over the indices from l to r (inclusive) to find the index that can be reached with the farthest jump.
Update farthest by taking the maximum of its current value and the sum of the current index i and the jump length nums[i].
After the inner loop, we have determined the farthest index we can reach from the current reachable indices.
Update l to be r + 1, as all the indices from the old right boundary r to the new right boundary farthest are reachable with the same number of jumps.
Update r to be the newly calculated farthest, as this becomes the new right boundary for the reachable indices.
Increment res by 1, as we have made a jump from the current reachable indices.
Repeat the loop until the right boundary r is greater than or equal to the last index (n - 1).
Finally, return res, which represents the minimum number of jumps required to reach the last index.
*/

/*

The condition r < n - 1 ensures that the loop continues until we reach or exceed the last index. If the right boundary r is already at the last index, it means we have already reached the end, and there is no need to continue.

*/
