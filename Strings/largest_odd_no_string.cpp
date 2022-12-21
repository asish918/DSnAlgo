#include <iostream>
using namespace std;

int main(){
    string num = "35728";

    string res = "";
    
    for(int i = num.length() - 1; i>=0; i--){
        int check_num = num[i] - '0';
        if(check_num % 2 != 0){
            res+=num.substr(0, i + 1);
            break;
        }
    }

    cout << res << endl;

    return 0;
}
