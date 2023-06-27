#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

string remove_K_Digits(string s, int k){
    stack<char> st;
    int count = k;

    for(int i = 0; i<s.length(); i++){
        while(count > 0 && !st.empty() && st.top() > s[i]){
            count--;
            st.pop();
        }

        st.push(s[i]);
    }

    while(st.size() != s.length() - k) st.pop();

    string res = "";

    while(!st.empty()){
        res += st.top();
        st.pop();
    }

    reverse(res.begin(), res.end());

    while(res[0] == '0') res.erase(0, 1);

    return (res == "") ? "0" :  res;

}

int main(){
    string num = "1432219";
    int k = 3;
    
    cout << remove_K_Digits(num, k);
    return 0;
}

/*
stack<char> st;: This line declares a stack called st to store characters from the string.

int count = k;: This initializes a counter variable count with the value of k, representing the number of digits to be removed.

The for loop iterates over each character in the input string s:

a. while(count > 0 && !st.empty() && st.top() > s[i]): This nested while loop executes as long as the following conditions are met:

count is greater than 0 (there are still digits to be removed).
The stack st is not empty.
The top element of the stack is greater than the current character s[i] being examined.
Inside the loop, count is decremented, and the top element of the stack is removed using st.pop().
b. st.push(s[i]);: After the inner while loop, the current character s[i] is pushed onto the stack st.

while(st.size() != s.length() - k) st.pop();: This while loop runs until the size of the stack st becomes equal to the difference between the length of the input string s and the number of digits to be removed k. The purpose is to remove any remaining elements from the stack that are not required.

string res = "";: This line declares an empty string res to store the result.

The next while loop appends the characters from the stack st to the result string res while popping each element from the stack.

reverse(res.begin(), res.end());: This reverses the characters in the result string res to obtain the correct order.

while(res[0] == '0') res.erase(0, 1);: This while loop removes any leading zeros from the result string res by erasing them.

Finally, the function returns the resulting string res, or if it is empty, it returns "0" as the smallest possible number.
*/
