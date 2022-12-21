#include <iostream>
using namespace std;

int main(){
    string s = "anagram";
    string t = "nagaram";

    int check_hash[26] = {0};
    bool flag = true;

    for(int i = 0; i<s.length(); i++){
        check_hash[s[i] - 'a']++;
        check_hash[t[i] - 'a']--;
    }

    for(int i = 0; i<26; i++){
        if(check_hash[i]) flag = false;
    }

    cout << flag << endl;

    return 0;
}
