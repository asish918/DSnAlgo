#include <iostream>
using namespace std;

bool canJump(int jump[], int n){
    int goal = n - 1;

    for(int i = n - 1; i>=0; i--)
        if(i + jump[i] >= goal)
            goal = i;

    return goal == 0;
}

int main(){
    int jump[] = {2, 3, 1, 1, 4};
    int n = sizeof(jump) / sizeof(int);

    cout << canJump(jump, n);

    return 0;
}
