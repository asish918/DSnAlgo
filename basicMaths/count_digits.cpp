#include <iostream>
using namespace std;

class Solution
{
public:
    int evenlyDivides(int N)
    {
        int count = 0;
        int x = N;
        while (x)
        {
            int digit = x % 10;
            if (digit != 0)
            {
                if (N % digit == 0)
                {
                    count++;
                }
            }
            x = x / 10;
        }
        return count;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long X;
        cin >> X;
        Solution ob;
        cout << ob.evenlyDivides(X) << endl;
    }

    return 0;
}
