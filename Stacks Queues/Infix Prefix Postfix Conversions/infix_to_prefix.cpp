#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int precedence(char c) {
    if(c == '^')
        return 3;
    else if(c == '/' || c == '*')
        return 2;
    else if(c == '+' || '-')
        return 1;
    
    return -1;
}


string inToPos(string in) {
    stack<char> st;
    string pos = "";
    
    for(int i = 0; i<in.length(); i++) {
        char c = in[i];

        if(isalnum(c))
            pos+=c;
        else if(c == '(')
            st.push(c);
        else if(c== ')') {
            while(!st.empty() && st.top() != '('){
                pos += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while(!st.empty() && precedence(c) < precedence(st.top())) {
                pos += st.top();
                st.pop();
            }

            st.push(c);
        }
    }

    while(!st.empty()) {
        pos += st.top();
        st.pop();
    }

    return pos;
}

int main() {
    string in = "x+y*z/w+u";
    reverse(in.begin(), in.end());

    for(int i = 0; i<in.length(); i++) {
        if(in[i] == '(')
            in[i] = ')';
        else if(in[i] == ')')
            in[i] = '(';
    }

    string pre = inToPos(in);
    reverse(pre.begin(), pre.end());

    cout << pre << endl;
    return 0;
}
