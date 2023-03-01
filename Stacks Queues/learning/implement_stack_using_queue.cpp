#include <iostream>
#include <iterator>
#include <queue>
using namespace std;

void pushWith1q(queue<int> & q, int value){
    q.push(value);

    for(int i = 0; i<q.size() - 1; i++){
        q.push(q.front());
        q.pop();
    }
}

void push(queue<int> &q1, queue<int> &q2, int value){
    q2.push(value);

    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }

    while(!q2.empty()){
        q1.push(q2.front());
        q2.pop();
    }
}

int pop(queue<int> &q){
    int val = q.front();
    q.pop();
    return val;
}

void printStack(queue<int> q){
    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
}

int main(){
    queue<int> q1;
    queue<int> q2;

    pushWith1q(q1, 1);
    pushWith1q(q1, 2);
    pushWith1q(q1, 3);

    pop(q1);
    pop(q1);
    pop(q1);

    //push(q1, q2, 1);
    //push(q1, q2, 2);
    //push(q1, q2, 3);
    //push(q1, q2, 4);
    //push(q1, q2, 5);

    printStack(q1);

    return 0;
}
