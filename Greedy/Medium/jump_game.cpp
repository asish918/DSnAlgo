#include <iostream>
using namespace std;

bool canJump(int jump[], int n){
    int goal = n - 1;

    for(int i = n - 1; i>=0; i--)
        if(i + jump[i] >= goal)
            goal = i;

    return goal == 0;
}

int main(){
    int jump[] = {2, 3, 1, 1, 4};
    int n = sizeof(jump) / sizeof(int);

    cout << canJump(jump, n);

    return 0;
}

/*
In this modified approach, we start iterating from the second-to-last index (n-2) and move towards the first index. At each index, we check if we can reach the last reachable index from the current index. If we can, we update the lastReachable variable with the current index.

By iterating from the end of the array, we are able to find the earliest index from where we can reach the last index. If the lastReachable variable becomes 0 after iterating through the array, it means we can reach the last index starting from the first index, so we return true. Otherwise, we return false.

This modified approach also has a time complexity of O(n), where n is the number of elements in the jumps array, as we iterate through the array only once, starting from the end.
*/
