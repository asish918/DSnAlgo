#include<iostream>
#include <string>
using namespace std;

int main(){
    string s = "Asish";

    int i = 0;
    int j = s.size() - 1;

    while(i <= j){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;

        i++;
        j--;
    }

    cout << s << endl;

    return 0;
}
