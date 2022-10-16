//Space complexity O(n1 + n2) still not optimised

#include <iostream>
using namespace std;

void insertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];

        int j = i - 1;
        while (j >= 0)
        {
            if (temp < arr[j])
            {
                arr[j + 1] = arr[j];
            }
            else
                break;
            j--;
        }
        arr[j + 1] = temp;
    }
}

void mergeTwoSortNaive(int arr1[], int n1, int arr2[], int n2)
{
    int i = 0, j = 0, k = 0;
    int arr3[n1 + n2];

    while (i < n1)
    {
        arr3[k++] = arr1[i++];
    }
    while (j < n2)
    {
        arr3[k++] = arr2[j++];
    }

    insertionSort(arr3, n1 + n2);

    for (k = 0; k < n1 + n2; k++)
    {
        cout << arr3[k] << " ";
    }
}

// Without any Sorting algo
void mergeTwoSortOptimal(int arr1[], int n1, int arr2[], int n2)
{
    int arr3[n1 + n2];
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }

    while (i < n1)
    {
        arr3[k++] = arr1[i++];
    }

    while (j < n2)
    {
        arr3[k++] = arr2[j++];
    }

    for (i = 0; i < n1 + n2; i++)
    {
        cout << arr3[i] << " ";
    }
}

int main()
{
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};
    int n1 = sizeof(arr1) / sizeof(int);
    int n2 = sizeof(arr2) / sizeof(int);

    // mergeTwoSortNaive(arr1, n1, arr2, n2);
    mergeTwoSortOptimal(arr1, n1, arr2, n2);

    return 0;
}