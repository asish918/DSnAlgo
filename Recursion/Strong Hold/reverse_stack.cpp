#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &st, int element){
    if(st.empty()){
        st.push(element);
        return;
    }

    int num = st.top();
    st.pop();

    insertAtBottom(st, element);

    st.push(num);
}

void reverseStack(stack<int> &st){
    if(st.empty())
        return;

    int num = st.top();
    st.pop();

    reverseStack(st);
    insertAtBottom(st, num);
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
    st.push(3);
    st.push(2);
    st.push(1);
    st.push(7);
    st.push(6);

    reverseStack(st);

    printStack(st);
    
    return 0;
}
