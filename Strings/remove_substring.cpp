#include<iostream>
using namespace std;

int main(){
  string s = "daabcbaabcbc";
  string part = "abc";

  while(s.length() && s.find(part) < s.length())
    s.erase(s.find(part), part.length());

  cout << s << endl;

  return 0;
}
