#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int space_optimisation(string s1, string s2) {
    int M = s1.length();
    int N = s2.length();

    int prev[N + 1];
    int curr[N + 1];
    memset(prev, 0, sizeof(prev));
    memset(curr, 0, sizeof(curr));

    for(int index1 = 1; index1 <= M; index1++) {
        for(int index2 = 1; index2 <= N;  index2++) {
            if(s1[index1 - 1] == s2[index2 - 1])
                curr[index2] = 1 + prev[index2 - 1];
            else
                curr[index2] = max(prev[index2], curr[index2 - 1]);
        }
        memcpy(prev, curr, sizeof(curr));
    }

    return N - curr[N] + M - curr[N]; //Deletions + Insertions
}

int main() {
    string s1 = "heap";
    string s2 = "pea";
        
    cout << space_optimisation(s1, s2) << endl;

    return 0;
}
