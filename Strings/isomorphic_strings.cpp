#include<iostream>
using namespace std;

int main(){
    string s = "egg";
    string t = "add";

    char shash[128] = {0};
    char thash[128] = {0};

    for(int i = 0; i<s.length(); i++) {
        if(shash[s[i]] != 0 && shash[s[i]] != t[i]){
            cout << "False" << endl;
            return 0;
        }
        if(thash[t[i]] != 0 && thash[t[i]] != s[i]){
            cout << "False" << endl;
            return 0;
        }

        shash[s[i]] = t[i];
        thash[t[i]] = s[i];
    }
    
    cout << "True" << endl;

    return 0;
}
