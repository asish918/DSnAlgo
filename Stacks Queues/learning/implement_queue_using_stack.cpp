#include <iostream>
#include <stack>
using namespace std;

void push(stack<int>&s1, stack<int>&s2, int value){
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }

    s1.push(value);

    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
}

void printQueue(stack<int> s){
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
}

int main(){
    stack<int> s1;
    stack<int> s2;

    push(s1, s2, 1);
    push(s1, s2, 2);
    push(s1, s2, 3);
    push(s1, s2, 4);
    push(s1, s2, 5);

    printQueue(s1);
    return 0;
}
