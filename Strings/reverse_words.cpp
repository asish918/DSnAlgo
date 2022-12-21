#include<iostream>
#include <stack>
using namespace std;

int main(){
    string s = "the sky is blue";

    stack<string> st;
    string temp = "";

    for(int i = 0; i<s.length(); i++){
        if(s[i] != ' ')
            temp+=s[i];
        else {
            st.push(temp);
            temp = "";
        };
    }
    st.push(temp);

    string res = "";
    while(!st.empty()){
        temp = st.top();
        st.pop();
        res+=temp + " ";
    }
    res.pop_back();
    cout << res << endl;
    return 0;
}
