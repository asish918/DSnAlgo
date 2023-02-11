#include<iostream>
#include <iterator>
#include <map>
using namespace std;

int main(){
    map<int, string, greater<int>> m({
{1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},
                            {50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}
            });

    string res = "";
    int num = 1994;

    map<int, string>::iterator i = m.begin();
    while(i != m.end()){
        if(num < i->first)
            i++;
        else{
            num -= i->first;
            res += i->second;
        }
    }

    cout << res << endl;

    return 0;
}
