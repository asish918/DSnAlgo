#include <iostream>
using namespace std;

char maxOccuringCharacter(string s){
  int arr[26] = {0};

  for(int i = 0; i<s.length(); i++){
    char ch = s[i];
    int number = ch - 'a';
    arr[number]++;
  }

  int maxi = -1;
  int ans = 0;
  for(int i = 0; i<26; i++){
    if(arr[i] > maxi){
      ans = i;
      maxi = arr[i];
    }
  }

  char finalAnswer = ans + 'a';
  return finalAnswer;
}

int main(){
  string s = "output";

  cout << maxOccuringCharacter(s) << endl;

  return 0;
}
