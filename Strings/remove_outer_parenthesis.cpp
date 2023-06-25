#include<iostream>
using namespace std;

int main() {
    string s = "(()())(())(()(()))";
    
    string res = "";
    int balance = 0;
    int start = 0;

    for(int i = 0; i<s.length(); i++) {
        if(s[i] == '(')
            balance++;
        else if(s[i] == ')')
            balance--;

        if(balance == 0) {
            res += s.substr(start + 1, i - start - 1);
            start = i + 1;
        }
    }

    cout << res << endl;

    return 0;
}
