#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 1, 3, 5, 6, 4};
    int n = sizeof(arr) / sizeof(int);

    int low = 0;
    int high = n - 1;
    int mid = low + (high - low) / 2;

    int index = -1;

    while(low < high){
        if(arr[mid] <= arr[mid+1])
            low = mid + 1;
        else
            high = mid;
        
        mid = low + (high - low) / 2;
    }

    cout << low << endl;

    return 0;
}