#include<iostream>
using namespace std;

int stringToInt(string s, int index){
    if(index == 0)
        return s[index]-'0';

    int value = stringToInt(s, index - 1);

    int curr = s[index]-'0';
    return value*10 + curr;
}

int main(){
    string s = "42";

    int ans = stringToInt(s, s.length() - 1);

    cout << ans << endl;

    return 0;
}
