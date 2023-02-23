#include <iostream>
#include <vector>
using namespace std;

int numberOfSubstrings(string s){
    int i = 0, j = 0, total = 0, n = s.length();
    vector<int> m(3);

    for(int i = 0; i<n; i++){
        if(m[0] > 0 && m[1] > 0 && m[2] > 0){
            total += (n - j + 1);
            if(s[i] == 'a') m[0]--;
            if(s[i] == 'b') m[1]--;
            if(s[i] == 'c') m[2]--;
            continue;
        }
        while(j < n && (m[0] == 0 || m[1] == 0 || m[2] == 0)){
            if(s[j] == 'a') m[0]++;
            if(s[j] == 'b') m[1]++;
            if(s[j] == 'c') m[2]++;
            j++;
        }

        if(m[0] > 0 && m[1] > 0 && m[2] > 0)
            total+=(n - j + 1);

        if(s[j] == 'a') m[0]--;
        if(s[j] == 'b') m[1]--;
        if(s[j] == 'c') m[2]--;
    }

    return total;
}

int main(){
    string s = "abc";

    cout << numberOfSubstrings(s);

    return 0;
}
