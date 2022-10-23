#include <iostream>
using namespace std;

int main()
{
    int arr[] = {-1, 0, 3, 5, 9, 12};
    int n = sizeof(arr) / sizeof(int);
    int x = 9;

    int low = 0;
    int high = n - 1;
    int mid = low + (high - low) / 2;

    while (low <= high)
    {
        if (arr[mid] == x)
        {
            cout << mid << endl;
            break;
        }

        else if (arr[mid] > x)
            high = mid - 1;

        else
            low = mid + 1;

        mid = low + (high - low) / 2;
    }

    return 0;
}