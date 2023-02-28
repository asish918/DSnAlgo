#include <iostream>
using namespace std;

int arr[10];
int size_q = 0;
int front = -1;
int rear = -1;

void push(int value){
    if(size_q >= 10)
        return;

    size_q++;
    if(front < 0)
        front++;

    arr[++rear] = value;
}

int pop(){
    if(size_q <= 0 || front > rear)
        return -1;
    size_q--;
    return arr[front++];
}

void printQueue(){
    if(size_q <= 0)
        return;

    for(int i = front; i <= rear; i++)
        cout << arr[i] << " ";
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(4);
    push(4);
    push(4);
    push(4);
    push(4);
    push(4);
    push(8);


    cout << size_q << endl;
    cout << front << endl;

    printQueue();
    return 0;
}
