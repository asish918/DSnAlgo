#include <algorithm>
#include<iostream>
using namespace std;

int main(){
    string s = "abcde";
    string goal = "bcdea";

    bool flag = false;

    int len = s.length();

    while(len--) {
        if(s == goal) flag = true;

        s = s.substr(1) + s[0];
    }

    cout << flag << endl;
    return 0;
}
