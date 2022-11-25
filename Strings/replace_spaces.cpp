#include<iostream>
using namespace std;

int main(){
  string s = "hello world";

  string str = "";

  for(int i = 0; i<s.length(); i++){
    if(s[i] ==  ' '){
      str.push_back('@');
    }
    else
      str.push_back(s[i]);
  }

  cout << str << endl;
  return 0;
}
