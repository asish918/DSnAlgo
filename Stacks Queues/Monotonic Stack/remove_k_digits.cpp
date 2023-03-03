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
