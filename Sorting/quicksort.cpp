#include <iostream>
using namespace std;

int partition(int* arr, int s, int e)
{
    // Starting element as pivot
    // int pivot = arr[s];
    // int count = 0;

    // for (int i = s + 1; i <= e; i++)
    // {
    //     if (arr[i] <= pivot)
    //         count++;
    // }

    // int pivotIndex = s + count;

    // int temp = arr[s];
    // arr[s] = arr[pivotIndex];
    // arr[pivotIndex] = temp;

    // int i = s, j = e;

    // while (i < pivotIndex && j > pivotIndex)
    // {
    //     while (arr[i] < pivot)
    //         i++;

    //     while (arr[j] > pivot)
    //         j--;

    //     if (i < pivotIndex && j > pivotIndex)
    //     {
    //         temp = arr[i];
    //         arr[i] = arr[j];
    //         arr[j] = temp;
    //         i++;
    //         j--;
    //     }
    // }

    // End element as pivot
    int pivot = arr[e];
    int i = s - 1;

    for(int j = s; j <= e - 1; j++){
        if(arr[j] <= pivot){
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[e];
    arr[e] = temp;

    return i + 1;
}

void quickSort(int* arr, int s, int e)
{
    if (s >= e)
        return;

    int p = partition(arr, s, e);

    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main()
{
    int arr[] = {24, 28, 38, 43, 14, 40, 1, 54};
    int n = sizeof(arr) / sizeof(int);

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}