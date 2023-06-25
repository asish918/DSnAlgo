#include <climits>
#include<iostream>
#include<stack>
#include<utility>
using namespace std;

stack<pair<int, int>> st;
int mini = INT_MAX;

void insert(int val) {
    if(st.empty()){
        st.push(make_pair(val, val));
        mini = val;
    }
    else {
        if(val < mini)
            mini = val;

        st.push(make_pair(val, mini));
    }
}

void pop() {
    if(st.empty())
        return;

    int element = st.top().first;
    int minElement = st.top().second;
    st.pop();

    mini = st.top().second;
}

int top() {
    return st.top().first;
}

int getMin() {
    return mini;
}

int main() {
    insert(-2);
    insert(0);
    insert(-3);

    cout << getMin() << endl;
    pop();
    cout << top() << endl;
    cout << getMin() << endl;
    
    cout << "-----" << endl;
    while(!st.empty()){
        cout << st.top().first << " " << st.top().second << endl;
        st.pop();
    }
    return 0;
}
