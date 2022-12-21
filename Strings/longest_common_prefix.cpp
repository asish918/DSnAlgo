#include<iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    vector<string> strs  { "cir", "car" };

    string temp = strs[0];

    for(int i = 1; i<strs.size(); i++){
        string prefix_check = "";

        int j = 0;
        while(j < strs[i].length()){
            if(strs[i][j] == temp[j])
                prefix_check+=strs[i][j];
            else{
                break;
            }
            j++;
        }

        if(prefix_check.length() < 1){
            temp = "";
            break;
        }
        else {
            temp = prefix_check;
            prefix_check = "";
        }
    }

    cout << temp << endl;

    return 0;
}
