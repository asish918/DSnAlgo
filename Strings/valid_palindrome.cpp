#include<iostream>
using namespace std;

string toLowerCase(string s){
    int i = 0;
    while(i <= s.size() - 1){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = s[i] - 'A' + 'a';
        }
        i++;
    }

    return s;
}

bool isValidChar(char s){
    if((s >= 'A' && s <= 'Z') || (s >= 'a' && s >= 'z') || (s >= '0' && s <= '9'))
        return true;

    else
        return false;
}

bool valid_palindrome(string s){
    string t = toLowerCase(s);

    int i = 0;
    int j = t.size() - 1;
    while(i <= j){
        if(isValidChar(t[i])){
            if(t[i] != t[j])
             return false;
        }
        i++;
        j--;
    }
    return true;
}

int main(){
    string s = "A man, a plan, a canal: Panama";
    
    cout << valid_palindrome(s) << endl;
    cout << toLowerCase(s);
    return 0;
}
