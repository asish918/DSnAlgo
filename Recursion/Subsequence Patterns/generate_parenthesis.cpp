#include <iostream>
#include <vector>
using namespace std;

void generate_parens(int n, int open, int close, vector<string>& ans, string s){
    if(open == n && close == n){
        ans.push_back(s);
        return;
    }

    if(open < n)
        generate_parens(n, open+1, close, ans, s+'(');
    if(close < open)
        generate_parens(n, open, close+1, ans, s+')');
}

int main(){
    int N = 3;

    string s;

    vector<string> ans;

    generate_parens(N, 0, 0, ans, s);

    for(auto i : ans){
        cout << i << " ";
    }

    cout << endl;

    return  0;
}
