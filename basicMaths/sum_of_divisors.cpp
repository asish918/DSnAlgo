#include <iostream>
using namespace std;

class Solution
{
public:
    long long sumOfDivisors(int N)
    {
        // Write Your Code here
        long long sum = 0;

        // for (int i = 1; i <= N; i++)
        // {
        //     for (int j = 1; j <= i; j++)
        //     {
        //         if (i % j == 0)
        //             sum += j;
        //     }
        // }

        // return sum;

        // Optimised O(n)
        for (int i = 1; i <= N; i++)
        {
            sum += (N / i) * i;
        }

        return sum;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        long long ans = ob.sumOfDivisors(n);
        cout << ans << endl;
    }
}