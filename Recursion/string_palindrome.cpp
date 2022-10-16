#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Solution
{
    // To remove all the non Alphanumeric Characters
    bool validCharacter(char ch)
    {
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9')
        {
            return 1;
        }
        return 0;
    }

    // To lowercase all the character
    char toLowerCase(char ch)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        {
            return ch;
        }
        else
        {
            char temp = ch + 32; // its same thing
            // char temp = ch -'A'+'a';
            return temp;
        }
    }

    // To check Palindrom
    bool checkpPalindrome(string s)
    {
        int start = 0, end = s.length() - 1;
        while (start <= end)
        {
            if (s[start] != s[end])
            {
                return 0;
            }
            else
            {
                start++;
                end--;
            }
        }
        return 1;
    }

public:
    bool isPalindrome(string s)
    {
        string str = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (validCharacter(s[i]))
            {
                str.push_back(s[i]);
            }
        }

        for (int j = 0; j < str.length(); j++)
        {
            str[j] = toLowerCase(str[j]);
        }
        return checkpPalindrome(str);
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;

        cout << ob.isPalindrome(s) << "\n";
    }

    return 0;
}