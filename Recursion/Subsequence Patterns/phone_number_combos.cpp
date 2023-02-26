#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void phone_combos(int index, string ans, string digits, unordered_map<char, vector<char> > hashmap){

    if(digits.length() == ans.length()){
        cout << ans << endl;
        return;
    }

    for(int i = 0; i<hashmap[digits[index]].size(); i++){
        phone_combos(i + 1, ans + hashmap[digits[index]][i], digits, hashmap);
    } 
}

int main(){

    unordered_map<char, vector<char> > hashmap;

    hashmap['2'] = {'a', 'b', 'c'};
    hashmap['3'] = {'d', 'e', 'f'};
    hashmap['4'] = {'g', 'h', 'i'};
    hashmap['5'] = {'j', 'k', 'l'};
    hashmap['6'] = {'m', 'n', 'o'};
    hashmap['7'] = {'p', 'q', 'r', 's'};
    hashmap['8'] = {'t', 'u', 'v'};
    hashmap['9'] = {'w', 'x', 'y', 'z'};
    string s = "23";

    phone_combos(0, "", s, hashmap);

    return 0;
}
