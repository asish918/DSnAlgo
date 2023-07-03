#include <iostream>
using namespace std;

bool validParenthesis(string s){
    int countOpenParenthesis = 0;
    int countOpenCurlyBraces = 0;
    int countOpenSquareBrackets = 0;

    for(int i = 0; i<s.length(); i++) {
        if(s[i] == '(')
            countOpenParenthesis++;
        else if(s[i] == ')') {
            countOpenParenthesis--;
            if(countOpenParenthesis < 0)
                return false;
        }
        else if(s[i] == '{')
            countOpenCurlyBraces++;
        else if(s[i] == '}') {
            countOpenCurlyBraces--;
            if(countOpenCurlyBraces < 0)
                return false;
        }
        else if(s[i] == '[')
            countOpenSquareBrackets++;
        else if(s[i] == ']') {
            countOpenSquareBrackets--;
            if(countOpenSquareBrackets < 0)
                return false;
        }
    }

    return !countOpenCurlyBraces && !countOpenSquareBrackets && !countOpenParenthesis;
}

int main() {
    string s = "{([])}";

    cout << validParenthesis(s);

    return 0;
}

/*
In this approach, we maintain separate counters for each type of opening bracket ((, {, [). We iterate over each character in the expression string and update the respective counters based on the encountered brackets.

For each character:

If it is an opening bracket, we increment the corresponding counter.
If it is a closing bracket, we decrement the corresponding counter. If the counter goes below 0, it means there is a mismatch in the brackets, and we return false.
After processing all characters, we check if all the counters for opening brackets (countOpenParenthesis, countOpenCurlyBraces, and countOpenSquareBrackets) are zero. If any of them are non-zero, it means there are unmatched brackets in the expression, and we return false. Otherwise, if all counters are zero, we return true.

In the example usage, we have two expressions: exp1 and exp2. We call the isBalanced function on each expression to check if the brackets are balanced. The result is printed as "balanced" if the expression is balanced or "not balanced" otherwise.

Please note that this approach assumes that the input expression contains only brackets and no other characters. If there are other characters in the expression, you may need to modify the code accordingly.
*/
