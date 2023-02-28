#include <climits>
#include<iostream>
#include<stack>
using namespace std;

int mini = INT_MAX;

void push(stack<long>&st, int value){
    if(st.empty()){
        mini = value;
        st.push(value);
    }
    else {
        if(value < mini){
            st.push(2 * value * 1LL - mini);
            mini = value;
        }
        else {
            st.push(value);
        }
    }
}

void pop(stack<long>&st){
    if(st.empty()) return;

    long el = st.top();
    st.pop();

    if(el < mini){
        mini = 2 * mini - el;
    }
}

int top(stack<int>&st){
    if(st.empty()) return -1;

    long el = st.top();
    if(el < mini)
        return mini;
    return el;
}

int getMin(){
    return mini;
}

int main(){
    stack<long> st;

    push(st, -2);
    push(st, 0);
    push(st,  -3);

    cout << getMin();

    return 0;
}
