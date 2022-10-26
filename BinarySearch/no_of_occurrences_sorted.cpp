#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 1, 2, 2, 2, 2, 3};
    int n = sizeof(arr) / sizeof(int);
    int x = 2;

    int count = 0;

    int low = 0;
    int high = n - 1;
    int mid = low + (high - low) / 2;

    while (low <= high)
    {
        if (x <= arr[mid])
        {
            if (arr[mid] == x)
                count++;
            high = mid - 1;
        }
        else
            low = mid + 1;
        mid = low + (high - low) / 2;
    }

    low = 0;
    high = n - 1;
    mid = low + (high - low) / 2;

    while (low <= high)
    {
        if (x >= arr[mid])
        {
            if (x == arr[mid])
                count++;
            low = mid + 1;
        }
        else
            high = mid - 1;
        mid = low + (high - low) / 2;
    }

    cout << count << endl;

    return 0;
}