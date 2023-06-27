#include <iostream>
#include <algorithm>
using namespace std;

int maxPoints(int arr[], int n, int k){
    int l = 0, r = n - k;
    int maxWindowSum = 0;

    for(int i = r; i<n; i++)
        maxWindowSum+=arr[i];

    int ans = maxWindowSum;

    while(r < n){
        maxWindowSum+= arr[l] - arr[r];
        ans = max(maxWindowSum, ans);
        r++;
        l++;
    }

    return ans;

}

int main(){
    int cardPoints[] = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    int n = sizeof(cardPoints)/sizeof(int);

    cout << maxPoints(cardPoints, n, k);
    return 0;
}

/*
The maxScore function takes a vector cardPoints containing the points of each card, an integer N representing the total number of cards, and an integer k representing the number of cards to be taken.
We initialize two pointers l and r. Pointer l represents the left boundary of the window, and pointer r represents the right boundary of the window. Initially, l is set to 0, and r is set to N - k, which defines the first window of size (N - k).
We initialize a variable total to store the sum of the points within the current window.
We iterate through the elements from r to N - 1 and add their points to the total to calculate the initial sum of the first window.
We set ans equal to total, which represents the current maximum score.
Using a sliding window approach, we start sliding the window to the right by incrementing both l and r.
In each iteration, we update the total by subtracting the point of the card at index r and adding the point of the card at index l. This represents moving the window one step to the right.
We update ans by taking the maximum of the current total and the previous ans, capturing the maximum score seen so far.
We repeat steps 7 and 8 until the window reaches the end of the array.
Finally, we return ans, which represents the maximum score.
*/
