#include <algorithm>
#include<iostream>
using namespace std;

int main(){
    string s = "abcde";
    string goal = "abced";

    bool flag = false;

    int maxRotations = s.size();

    while(maxRotations){
        if(!s.compare(goal)) flag = true;

        rotate(s.begin(), s.begin() + 1, s.end());

        maxRotations--;
    }

    cout << flag << endl;
    return 0;
}
