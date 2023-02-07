#include <iostream>
using namespace std;

int main(){
    int a = 13;
    int b = 9;

    a = a^b;
    b = b^a;
    a = a^b;

    cout << a <<  " " << b << endl;

    return 0;
}
