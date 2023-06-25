#include<iostream>
using namespace std;

//TC - O(n*n)
int bruteForce(int M[3][3], int n) {
    int ans = -1;

    for(int i = 0; i<n; i++) {
        bool isCelebrity = true;

        // Check if person 'i' knows anyone or if someone doesn't know person 'i'
        for(int j = 0; j<n; j++) {
            if(i != j && ((M[i][j]) || !(M[j][i]))) {
                isCelebrity = false;
                break;
            }
        }

        // If person 'i' is the celebrity, return its index
        if(isCelebrity)
            return i;
    }

    return -1;
}

//TC - O(2n) - O(n)
int optimal(int M[3][3], int n) {
    int left = 0;
    int right = n - 1;

    while(left < right) {
        if(M[left][right])
            left++;
        else
            right--;
    }

    int celebrity = left; //or right
    
    for(int i = 0; i<n; i++) {
        if(i != celebrity && (!M[i][celebrity] || M[celebrity][i]))
            return -1;
    }
    
    return celebrity;
}

int main() {
    int M[3][3] = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0},
    };

    int n = 3;

    cout << bruteForce(M, n) << endl;
    cout << optimal(M, n) << endl;

    return 0;
}

/*
##### Optimal Two-Pointer Approach
In the brute force solution, we iterated through each person and checked if they know anyone and if everyone knows them. However, we can observe that once we encounter a pair of people, say person A and person B, and person A knows person B, person A cannot be the celebrity. Similarly, if person A doesn't know person B, person B cannot be the celebrity. Therefore, we can eliminate some comparisons by using the two-pointer approach.

The basic idea of the two-pointer approach in this case is to use two pointers, left and right, initially pointing to the leftmost and rightmost columns of the matrix, respectively. We compare the knowledge relationship between the person at the left index and the person at the right index.

If the person at the left index knows the person at the right index (i.e., knows(left, right, matrix) is true), we can conclude that the person at the left index cannot be the celebrity. This is because a celebrity does not know anyone, so we move left one step to the right (++left).
If the person at the left index doesn't know the person at the right index (i.e., knows(left, right, matrix) is false), we can conclude that the person at the right index cannot be the celebrity. This is because a celebrity is known by everyone, so we move right one step to the left (--right).
We continue this process of comparing and updating the pointers until left and right meet (i.e., left < right). At this point, the potential celebrity is at the position of left (or right since they would have the same value). The reason is that all the people from left to right-1 cannot be the celebrity because they know at least one person (right), and the person at the right index doesn't know anyone. Therefore, the potential celebrity is either at the left or right index.

After finding the potential celebrity, we need to verify if they are indeed a celebrity. We iterate through all the people, excluding the potential celebrity itself, and check two conditions:

If anyone doesn't know the potential celebrity (i.e., !knows(i, celebrity, matrix)), then the potential celebrity cannot be the actual celebrity. We return -1 indicating that no celebrity was found.
If the potential celebrity knows anyone (i.e., knows(celebrity, i, matrix)), then the potential celebrity cannot be the actual celebrity. We return -1 indicating that no celebrity was found.
If both conditions pass for all the remaining people, the potential celebrity is indeed the celebrity, and we return their index.
 */
