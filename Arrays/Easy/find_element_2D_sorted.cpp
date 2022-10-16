#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int arr[1][6] = {
        {18, 21, 27, 38, 55, 67}};

    int X = 55;

    int flag = 0;

    int i = 0, j = 5;
    while (i < 1 && j >= 0)
    {
        if (arr[i][j] == X)
        {
            flag = 1;
            break;
        }
        else if (arr[i][j] > X)
        {
            j--;
        }
        else
            i++;
    }

    cout << flag << endl;

    return 0;
}