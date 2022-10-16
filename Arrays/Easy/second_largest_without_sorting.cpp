#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int max = arr[0];
    int max2 = arr[0];

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        if (arr[i] > max)
            max = arr[i];
        
    }

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++){
        if(arr[i] > max2 && arr[i] != max)
            max2 = arr[i];
    }

    cout << max2 << endl;
    return 0;
}