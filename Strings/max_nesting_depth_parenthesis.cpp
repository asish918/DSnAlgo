#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    string s = "(1)+((2))+(((3)))";

    stack<char> st;
    int count = 0;
    int ans = count;

    for(int i = 0; i<s.length(); i++){
        if(s[i] == '('){
            st.push(')');
            count++;
        }
        else if(s[i] == ')'){
            st.pop();
            count--;
        }

        ans = max(count, ans);
    }

    cout << ans << endl;

    return 0;
}
