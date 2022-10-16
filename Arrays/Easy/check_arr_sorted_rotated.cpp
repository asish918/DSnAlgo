// Need to work on this :(

#include <iostream>
using namespace std;

int main()
{
    int arr[] = {2, 1, 3, 4};
    int flagCount = 0;
    int flag = 0;

    for (int i = 0; i < (sizeof(arr) / sizeof(int)) - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            flagCount++;

        if (arr[i] <= arr[i + 1])
            continue;

        else
            flag = 1;
    }

    if (!flag || flagCount == 1)
        cout << "Sorted and rotated";

    else
        cout << "Not Sorted";
    cout << endl;
    return 0;
}