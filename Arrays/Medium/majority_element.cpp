#include <iostream>
using namespace std;

int main()
{
    int arr[] = {3, 1, 3, 3, 2};
    int N = 5;

    int count = 0;
    int element = 0;

    for (int i = 0; i < N; i++)
    {
        if (count == 0)
            element = arr[i];
        if (arr[i] == element)
            count++;
        else
            count--;
    }

    cout << element << endl;
    return 0;
}