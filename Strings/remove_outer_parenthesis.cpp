#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<char> s;
    string ques = "(()())(())";
    string res = "";

    int index = 0, pos = 0;

    while(index < ques.length()){
        if(ques[index] == '(')
            s.push(')');
        else
         s.pop();

        if(s.empty()){
            res+=ques.substr(pos + 1, index - pos - 1);
            pos = index + 1;
        }

        index++;
    }

    cout << res << endl;

    return 0;
}
