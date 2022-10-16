#include <iostream>
using namespace std;

int main()
{
    int arr[] = {8, 9, 10, 1, 2, 4, 3, 5, 6, 7};
    int flagCount = 0;
    int flag = 0;

    for (int i = 0; i < (sizeof(arr) / sizeof(int)) - 1; i++)
    {
        if (arr[i] <= arr[i + 1])
            continue;

        else
            flag = 1;
    }

    if (!flag)
        cout << "Sorted and rotated";

    else
        cout << "Not Sorted";
    cout << endl;
    return 0;
}
