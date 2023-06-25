#include <iostream>
#include <queue>
using namespace std;

bool isValid(string s) {
    int leftCount = 0;
    for(int i = 0; i<s.length(); i++) {
        if(s[i] == '(')
            leftCount++;
        else
            leftCount--;

        if(leftCount < 0)
            return false;
    }

    return leftCount == 0;
}

void bruteForce(int n){
    queue<string> q;
    q.push("(");
    q.push(")");

    while(!q.empty()) {
        string currString = q.front();
        q.pop();

        if(currString.length() == 2*n) {
            if (isValid(currString))
                cout << currString << " ";
            continue;
        }

        q.push(currString + "(");
        q.push(currString + ")");
    }
}

void optimalRecursion (int N, int open, int close, string ans) {
    if(ans.length() == 2*N) {
        cout << ans << " ";
        return;
    }

    if(open < N)
        optimalRecursion(N, open + 1, close, ans + "(");
    if(close < open)
        optimalRecursion(N, open, close + 1, ans + ")");
}

int main(){
    int N = 3;
    
    //bruteForce(N);
    optimalRecursion(N, 0, 0, "");
    
    return  0;
}
