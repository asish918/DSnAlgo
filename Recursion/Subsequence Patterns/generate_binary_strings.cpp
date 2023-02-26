#include <iostream>
using namespace std;

void printBinaryStrings(int n, string str){
    if(n == 0){
        cout << str << endl;
        return;
    }

    printBinaryStrings(n - 1, str+'0');

    if(str.back() != '1')
        printBinaryStrings(n - 1, str+'1');

}

int main(){
    string s = "";

    int N = 3;

    printBinaryStrings(N, s);

    return 0;
}
