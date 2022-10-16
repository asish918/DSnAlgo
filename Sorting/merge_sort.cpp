#include <iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    int len1 = s + mid + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int mainIndex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainIndex++];
    }

    mainIndex = mid + 1;
    for (int j = 0; j < len2; j++)
    {
        second[j] = arr[mainIndex++];
    }

    int i = 0, j = 0;
    mainIndex = s;

    while (i < len1 && j < len2)
    {
        if (first[i] < second[j]) // > for merge sort in descending order
            arr[mainIndex++] = first[i++];
        else
            arr[mainIndex++] = second[j++];
    }

    while (i < len1)
    {
        arr[mainIndex++] = first[i++];
    }

    while (j < len2)
    {
        arr[mainIndex++] = second[j++];
    }
}

void mergeSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int mid = s + (e - s) / 2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e);
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};

    mergeSort(arr, 0, 4);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
