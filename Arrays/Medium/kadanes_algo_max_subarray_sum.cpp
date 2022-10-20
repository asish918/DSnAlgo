#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, -2, 5};
    int N = sizeof(arr) / sizeof(int);

    int sum = 0;
    int maxi = arr[0];

    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
        maxi = max(sum, maxi);
        if (sum < 0)
            sum = 0;
    }

    cout << maxi << endl;

    return 0;
}