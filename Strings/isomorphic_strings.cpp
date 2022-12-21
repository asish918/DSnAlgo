#include<iostream>
using namespace std;

int main(){
    string s = "badc";
    string t = "baba";

    bool flag = true;

    char shash[128] = {0};
    char thash[128] = {0};

    for(int i = 0; i<s.length(); i++){
        if(shash[s[i]] != 0){
            if(shash[s[i]] != t[i])
                flag = false;
        }
        else
            shash[s[i]] = t[i];

        if(thash[t[i]] != 0){
            if(thash[t[i]] != s[i])
                flag = false;
        }
        else
            thash[t[i]] = s[i];
    }

    cout << flag << endl;

    return 0;
}
