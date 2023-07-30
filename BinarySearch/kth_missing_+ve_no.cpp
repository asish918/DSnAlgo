#include <iostream>
using namespace std;

int bruteForce(int arr[], int n, int k) {
    int ans = k;
    
    for(int i = 0; i < n; i++) {
        if(arr[i] <= ans)
            ans++;
        else break;
    }

    return ans;
}

int main()
{
    int arr[] = {1, 3, 4, 5, 7};
    int n = sizeof(arr) / sizeof(int);
    int k = 2;

    cout << bruteForce(arr, n, k) << endl;

    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int missing = (arr[mid] - (mid + 1));

        if (missing >= k)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << (high + 1 + k) << endl; //or Low + k (Low = high + 1);
    return 0;
}
