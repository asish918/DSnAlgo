#include <iostream>
using namespace std;

double multiply(double x, int y)
{
    double ans = 1.0;
    for (int i = 0; i < y; i++)
    {
        ans *= x;
    }
    return ans;
}

int main()
{
    int m = 22;
    int n = 3;

    double low = 0;
    double high = m - 1;
    double eps = 10e-6;

    while ((high - low) > eps)
    {
        double mid = low + (high - low) / 2;

        if (multiply(mid, n) < m)
            low = mid;
        else
            high = mid;
    }

    cout << low << endl;

    return 0;
}