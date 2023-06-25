#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {
    int asteroids[] = {3, 5, -3};
    int n = sizeof(asteroids) / sizeof(int);

    stack<int> st;

    for(int i = 0; i<n; i++) {
        int curr = asteroids[i];
        bool exploded = false; //keep track of explosion of current asteroid element

        while(!st.empty() && curr < 0 && st.top() > 0) {
            if(abs(curr) == st.top()) {
                exploded = true;
                st.pop();
                break;
            }
            else if(abs(curr) < st.top()) {
                exploded = true;
                break;
            }
            else {
                st.pop();
            }
        }

        if(!exploded)
            st.push(curr);
    }

    vector<int> res(st.size());

    for(int i = st.size() - 1; i>=0; i--) {
        res[i] = st.top();
        st.pop();
    }

    for(auto i : res)
        cout << i <<  " ";
    cout << endl;
    return 0;
}



/*
For each asteroid, we check if it can collide with the top asteroid in the stack. If the current asteroid is moving to the left (negative value) and the top asteroid in the stack is moving to the right (positive value), we compare their sizes to determine if a collision occurs. There are three possible scenarios:

If the sizes of both asteroids are equal, they both explode, so we pop the top asteroid from the stack.

If the current asteroid has a smaller size than the top asteroid, it explodes, so we don't push the current asteroid onto the stack.

If the current asteroid has a larger size than the top asteroid, the top asteroid explodes, so we pop it from the stack and continue the comparison with the next top asteroid.
If none of the above conditions apply, the current asteroid doesn't collide with any asteroid in the stack, so we push it onto the stack.

Finally, we extract the elements from the stack in reverse order and store them in the result vector, representing the state of the asteroids after all collisions.
*/
