#include <iostream>
using namespace std;

int main()
{
    int x = 1;
    for (int i = 1; i < 6; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << x;
        }
        x++;
        cout << endl;
    }

    return 0;
}

/*

1
22
333
4444
55555

*/