#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2};
    int n = sizeof(arr) / sizeof(int);

    queue<int> pos;
    queue<int> neg;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
            pos.push(arr[i]);
        else
            neg.push(arr[i]);
    }

    int j = 0;
    while (!pos.empty() && !neg.empty() && j < n)
    {
        if (j % 2 == 0)
        {
            arr[j] = pos.front();
            pos.pop();
        }

        if (j % 2 != 0)
        {
            arr[j] = neg.front();
            neg.pop();
        }

        j++;
    }

    while (!pos.empty() && j < n)
    {
        arr[j] = pos.front();
        pos.pop();
        j++;
    }

    while (!neg.empty() && j < n)
    {
        arr[j] = neg.front();
        neg.pop();
        j++;
    }

    for (j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }

    return 0;
}