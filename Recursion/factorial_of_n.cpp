/*
A number N is called a factorial number if it is the factorial of a positive integer. For example, the first few factorial numbers are 1, 2, 6, 24, 120, …
Given a number N, the task is to print all factorial numbers smaller than or equal to N.
*/

#include <iostream>
#include <vector>
using namespace std;

int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

vector<int> facts(int x)
{
    vector<int> v;
    int i = 1;
    while (factorial(i) <= x)
    {
        v.push_back(factorial(i));
        i++;
    }

    return v;
}

int main()
{

    vector<int> v = facts(6);
    for (int i : v)
    {
        cout << i << endl;
    }

    return 0;
}