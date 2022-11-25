#include<iostream>
#include <algorithm>
using namespace std;

int main(){
    string s = "the sky is blue";
    
    reverse(s.begin(), s.end());

    int index = 0;
    int l = 0;
    int r = 0;
    int n = s.size();

    while(index < n){
        bool isWord = false;
        while(index < n && s[index] != ' '){
            s[r] = s[index];
            r++;
            index++;

            isWord = true;
        }

        if(isWord){
            reverse(s.begin() + l, s.begin() + r);
            s[r] = ' ';
            r++;
            l = r;
        }

        index++;
    }
    
    s.resize(r-1);

    cout << s << endl;
    return 0;
}
