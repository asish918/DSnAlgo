#include <iostream>
using namespace std;

void revArr(int arr[], int s, int e)
{
    int i = s, j = e - 1;
    while (i <= j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int k = 12;
    int adjusted_k = k % (sizeof(arr) / sizeof(int));

    revArr(arr, 0, adjusted_k);
    revArr(arr, adjusted_k, sizeof(arr) / sizeof(int));
    revArr(arr, 0, sizeof(arr) / sizeof(int));

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
        cout << arr[i] << " ";

    return 0;
}