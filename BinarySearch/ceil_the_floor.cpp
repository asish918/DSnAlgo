#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    int arr[] = {5, 6, 8, 9, 6, 5, 5, 6};
    // 5, 5, 5, 6, 6, 6, 8, 9
    int n = sizeof(arr) / sizeof(int);
    int x = 7;

    sort(arr, arr+n);

    int low = 0;
    int high = n - 1;
    int mid = low + (high - low) / 2;

    int floor_val = -1;
    int ceil_val = -1;

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            floor_val = mid;
            ceil_val = mid;
            break;
        }
        else if (arr[mid] < x)
        {
            floor_val = mid;
            low = mid + 1;
        }
        else
        {
            ceil_val = mid;
            high = mid - 1;
        }
    }

    cout << arr[floor_val] << " " << arr[ceil_val] << endl;
    
    return 0;
}