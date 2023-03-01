#include <iostream>
using namespace std;

int arr[5];
int top = -1;

void push(int value){
    arr[++top] = value;
}

void pop(){
    top--;
}

int topEl(){
    return arr[top];
}

bool isEmpty(){
    if(top < 0)
        return true;

    return false;
}

void printStack(){
    for(int i = 0; i<5; i++)
        cout << arr[i] << " ";
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    
    printStack();
     
    return 0;
}
