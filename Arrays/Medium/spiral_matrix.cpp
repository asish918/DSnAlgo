#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> spiralMatrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int n = spiralMatrix.size();
    int m = spiralMatrix[0].size();

    //One Approach

    int top = 0, left = 0, right = m - 1, bottom = n - 1;

    while(top <= bottom && left <= right){
        for(int i = left; i<=right; i++)
            cout << spiralMatrix[top][i] << " ";
        top++;

        for(int i = top; i<= bottom; i++)
            cout << spiralMatrix[i][right] << " ";
        right--;

        if(top <= bottom) {
            for(int i = right; i>=left; i--)
                cout << spiralMatrix[bottom][i] << " ";
            bottom--;
        }

        if(left <= right){
            for(int i = bottom; i >= top; i--)
                cout << spiralMatrix[i][left] << " ";
            left++;
        }
    }
    return 0;
}
