#include<iostream>
#include <string>
using namespace std;

int compress(string s){
    int i = 0;
    int ansIndex = 0;
    int n = s.length();

    while(i<n){
       int j = i + 1;
       if(j < n && s[i] == s[j]){
           j++;
       }

       s[ansIndex++] = s[i];
       int count = j - i;

       if(count > 1){
           string ch = to_string(count);
           for(char c : ch)
               s[ansIndex++] = c;
       }
       i = j;
    }

    cout << s[ansIndex] << endl;
    return ansIndex;
}

int main(){
    string s = "aabbccc";

    cout << compress(s) << endl;

    return 0;
}
