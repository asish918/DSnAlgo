#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 8, 10, 11, 12, 19};
    int n = sizeof(arr) / sizeof(int);
    int x = 5;

    int low = 0;
    int high = n - 1;
    int mid = low + (high - low) / 2;

    int floor = -1;

    while (low <= high)
    {
        if (arr[mid] <= x)
        {
            floor = mid;
            low = mid + 1;
        }
        else if (arr[mid] > x)
        {
            high = mid - 1;
        }
        mid = low + (high - low) / 2;
    }

    cout << floor << endl;

    return 0;
}