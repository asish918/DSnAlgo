#include <iostream>
using namespace std;

bool validParenthesis(string s){
    int leftMin = 0, leftMax = 0;

    for(int i = 0; i<s.length(); i++){
        if(s[i] == '('){
            leftMax++;
            leftMin++;
        }
        else if(s[i] == ')'){
            leftMax--;
            leftMin--;
        }
        else {
            leftMin--;
            leftMax++;
        }

        if(leftMax < 0)
            return false;
        if(leftMin < 0)
            leftMin = 0;
    }

    return leftMin == 0;
}

int main() {
    string s = "()";

    cout << validParenthesis(s);

    return 0;
}
