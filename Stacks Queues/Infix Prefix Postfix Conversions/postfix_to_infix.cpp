#include<iostream>
#include<stack>
using namespace std;

int main() {
    stack<string> st;
    string pos = "ab*c+";

    for(int i = 0; i<pos.length(); i++) {
        char c = pos[i];

        if(isalnum(c)) {
            string ans(1, c);
            st.push(ans);
        }
        else {
            string left = st.top();
            st.pop();
            string right = st.top();
            st.pop();
            st.push("(" + right + c + left + ")");
        }
    }

    cout << st.top() << endl;
    return 0;
}
