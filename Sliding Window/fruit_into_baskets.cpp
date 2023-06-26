#include <climits>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

//Find longest subaray consisting of two distinct elements
int maxFruitsInBasket(int tree[], int n){
    int  i = 0, j = 0, ans = INT_MIN;
    unordered_map<int, int> mpp;

    while(j < n){
        mpp[tree[j]]++;
        
        while(mpp.size() > 2) {
            mpp[tree[i]]--;
            if(mpp[tree[i]] == 0)
                mpp.erase(tree[i]);
            i++;
        }

        ans = max(ans, j - i + 1);
        j++;
    }

    return ans;
}

int main(){
    int tree[] = {1, 2, 3, 2, 2};
    int n = sizeof(tree)/sizeof(int);

    cout << maxFruitsInBasket(tree, n);
    return 0;
}

/*
In this solution, we use an unordered map fruitCount to keep track of the count of each fruit in our window. The left and right pointers are used to define the boundaries of the window.

We iterate through the fruits vector using the right pointer. For each fruit, we check if it is already present in our window. If it is, we increment its count; otherwise, we add it to the window with a count of 1.

If the number of unique fruits in our window exceeds 2, we move the left pointer to the right until the window contains only two types of fruits. We decrease the count of the fruit at the left pointer and remove it from the window if its count reaches 0.

We update the maxFruits variable with the maximum value between maxFruits and the length of the current window (right - left + 1).

Finally, we return the maxFruits as the result.
*/
