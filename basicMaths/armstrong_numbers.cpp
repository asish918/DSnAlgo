#include <iostream>
using namespace std;

class Solution
{
public:
    string armstrongNumber(int n)
    {
        int sum = 0;
        int x = n;
        while (n)
        {
            int digit = n % 10;
            sum += digit * digit * digit;
            n = n / 10;
        }

        if (sum == x)
        {
            return "Yes";
        }
        else
            return "No";
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
        cout << ob.armstrongNumber(n) << endl;
    }
}