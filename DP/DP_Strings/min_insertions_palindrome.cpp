#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int space_optimisation(string s1, string s2) {
    int N = s1.length();

    int prev[N + 1];
    int curr[N + 1];
    memset(prev, 0, sizeof(prev));
    memset(curr, 0, sizeof(curr));

    for(int index1 = 1; index1 <= N; index1++) {
        for(int index2 = 1; index2 <= N;  index2++) {
            if(s1[index1 - 1] == s2[index2 - 1])
                curr[index2] = 1 + prev[index2 - 1];
            else
                curr[index2] = max(prev[index2], curr[index2 - 1]);
        }
        memcpy(prev, curr, sizeof(curr));
    }

    return N - curr[N];
}

int main() {
    string str = "abcd";
    string revStr = str;
    reverse(revStr.begin(), revStr.end());
        
    cout << space_optimisation(str, revStr) << endl;

    return 0;
}
