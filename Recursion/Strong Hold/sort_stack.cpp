#include <iostream>
#include <stack>
using namespace std;

void sortedInsert(stack<int>& st, int element){
    if(st.empty() || st.top() < element){
        st.push(element);
        return;
    }

    int num = st.top();
    st.pop();
    sortedInsert(st, element);
    st.push(num);
}

void sortStack(stack<int> &st){
    if(st.empty())
        return;

    int num = st.top();
    st.pop();

    sortStack(st);
    sortedInsert(st, num);
}

void printStack(stack<int> st){
    if(st.empty())
        return;

    cout << st.top() << endl;
    st.pop();

    printStack(st);
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);

    sortStack(st);

    printStack(st);
    return 0;
}
