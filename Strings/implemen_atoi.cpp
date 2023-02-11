#include<iostream>
using namespace std;

int main(){
    string s = "1234";
    
    int i = 0;
    int ans = 0;
    int flag = 0;

    if(s[i] == '-'){
        i = 1;
        flag = 1;
    }

    for(; i<s.length(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            ans = ans*10 + (s[i] - '0');
        }
        else {
            cout << "Invalid String" << endl;
            break;
        }
    }

    if(flag == 1)
        ans *= 1;

    cout << ans << endl;

    return 0;
}
