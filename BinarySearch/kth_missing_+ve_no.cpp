#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 3, 4, 5, 7};
    int n = sizeof(arr) / sizeof(int);
    int k = 2;

    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int missing = (arr[mid] - (mid + arr[0]));

        if (missing >= k)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (low == n)
        cout <<  -1 << endl;
    else
        cout << (high + arr[0] + k) << endl;
    return 0;
}