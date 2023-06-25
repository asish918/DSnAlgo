#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(string s, int start, int end){
    while(start <= end){
        if(s[start++] != s[end--])
            return false;
    }
    return true;
}

void palindrome_partition(int index, string s, vector<string>& ds){
    if(index == s.length()){
        for(auto i : ds)
            cout << i << " ";
        cout << endl;
        return;
    }

    for(int i = index; i<s.length(); i++){
        if(isPalindrome(s, index, i)){
            ds.push_back(s.substr(index, i - index + 1));
            palindrome_partition(i + 1, s, ds);
            ds.pop_back();
        }
    }
}

int main(){
    vector<string> ds;

    string s = "ababbbabbababa";

    palindrome_partition(0, s, ds);

    return 0;
}
