#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {5, 7, 7, 8, 8, 10};
    int n = sizeof(arr) / sizeof(int);
    int target = 8;

    int low = 0;
    int high = n - 1;
    int mid = low + (high - low) / 2;

    int first_occur = -1;
    int last_occur = -1;

    // First Occurence
    while (low <= high)
    {
        if (arr[mid] >= target)
        {
            if (arr[mid] == target)
                first_occur = mid;
            high = mid - 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        mid = low + (high - low) / 2;
    }

    // Last Occurence
    low = 0;
    high = n - 1;
    mid = low + (high - low) / 2;

    while (low <= high)
    {
        if (arr[mid] <= target)
        {
            if (arr[mid] == target)
                last_occur = mid;
            low = mid + 1;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        mid = low + (high - low) / 2;
    }

    cout << first_occur << " " << last_occur << endl;
    cout << lower_bound(arr, arr + n, target) - arr << " " << upper_bound(arr, arr + n, target) - arr - 1;

    return 0;
}
