#include<iostream>
#include<stack>
using namespace std;

int main() {
    string pre = "*-A/BC-/AKL";
    stack<string> st;

    for(int i = pre.length() - 1; i>=0; i--) {
        char c = pre[i];

        if(isalnum(c)) {
            string ans(1, c);
            st.push(ans);
        }
        else {
            string left = st.top();
            st.pop();
            string right = st.top();
            st.pop();
            st.push('(' + left + c + right + ')');
        }
    }

    cout << st.top() << endl;
    return 0;
}
