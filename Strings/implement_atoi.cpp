#include<iostream>
#include<climits>
#include<cctype>
using namespace std;

int main(){
    string s = "46";
    int ans = 0;
    int i = 0;
    int sign = 1;
    int n = s.length();

    while(i < n && s[i] == ' ')
        i++;

    if(i < n && (s[i] == '+' || s[i] == '-')) {
        sign = s[i] == '-' ? -1 : 1;
        i++;
    }

    while(i < n && isdigit(s[i])) {
        int digit = s[i] - '0';

        if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > INT_MAX % 10)) {
            sign == -1 ? cout << INT_MIN : cout << INT_MAX;
            return 0;
        }

        ans = ans * 10 + digit;
        i++;
    }
    
    sign == -1 ? cout << (-1) * ans : cout << ans << endl;

    return 0;
}

/*
###### Integer Overflow explaination

In this step, we perform the following checks to detect integer overflow:

We compare the current result value with INT_MAX / 10, which represents the maximum positive value that the result can have before adding the next digit. If the result is already greater than INT_MAX / 10, any additional digit will cause an overflow.

If the result is equal to INT_MAX / 10, we need to check the last digit of the current number (digit). We compare digit with INT_MAX % 10, which represents the maximum digit value that the result can have in the ones place.

*/

/*
####Approach
The myAtoi function takes a string s as input and returns the converted 32-bit signed integer.

We initialize variables i and n to keep track of the current index and the length of the string, respectively.

The sign variable is initialized to 1 by default, indicating a positive number.

The result variable is used to accumulate the converted integer value.

We start by ignoring any leading whitespace characters by incrementing i until either the end of the string is reached or a non-whitespace character is encountered.

Next, we check if the next character (if any) is '-' or '+', indicating a negative or positive number, respectively. We update the sign variable accordingly and move to the next character.

We then iterate through the remaining characters of the string while they are digits. We convert each digit character to its integer value and add it to the result.

Before adding each digit, we check for integer overflow according to the specified conditions: if the result is greater than INT_MAX / 10, or if it is equal to INT_MAX / 10 and the current digit is greater than INT_MAX % 10. If an overflow is detected, we return INT_MIN or INT_MAX depending on the sign.

After converting all the digits, we apply the sign to the result by multiplying it with sign.

Finally, we return the resulting integer.
 */
