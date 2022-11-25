#include <iostream>
#include <string>
using namespace std;

bool checkEqual(int count1[], int count2[]){
    for(int i = 0; i<26; i++){
        if(count1[i] != count2[i])
            return 0;
    }

    return 1;
}

bool checkInclusion(string s1, string s2){
    int count1[26] = {0};
    int i = 0;

    for(i = 0; i<s1.length(); i++){
        count1[s1[i] - 'a']++;
    }

    int windowSize = s1.length();
    int count2[26] = {0};

    i = 0;
    while(i < windowSize && i < s2.length()){
        count2[s2[i] - 'a']++;
        i++;
    }

    if(checkEqual(count1, count2))
        return 1;


    while(i < s2.length()){
        count2[s2[i] - 'a']++;
        count2[s2[i - windowSize] - 'a']--;
        i++;

        if(checkEqual(count1, count2))
            return 1;
    }


    return 0;
}

int main(){
    string s1 = "ab";
    string s2 = "eidbaooo";

    cout << checkInclusion(s1, s2) << endl;

    return 0;
}
