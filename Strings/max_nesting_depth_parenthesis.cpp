#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string s = "(1)+((2))+(((3)))";

    int count = 0;
    int ans = count;

    for(int i = 0; i<s.length(); i++){
        if(s[i] == '('){
            count++;
        }
        else if(s[i] == ')'){
            count--;
        }

        ans = max(count, ans);
    }

    cout << ans << endl;

    return 0;
}
