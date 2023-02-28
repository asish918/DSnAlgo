#include <iostream>
#include <stack>
using namespace std;

int main(){
    string s = "({[]})";

    stack<char> st;

    bool flag = false;

    for(int i = 0; i<s.length(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else{
            if(st.empty()){
                flag = false;
                break;
            }
            if(s[i] == ')' && st.top() != '('){
                flag = false;
                break;
            }
            if(s[i] == '}' && st.top() != '{'){
                flag = false;
                break;
            }
            if(s[i] == ']' && st.top() != '['){
                flag = false;
                break;
            }

            st.pop();
        }
    }
    
    flag = st.empty();

    cout << flag << endl;

    return 0;
}
