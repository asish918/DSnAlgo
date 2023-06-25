#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int i, int grid[9][9], int row, int col){
    for(int j = 0; j<9; j++){
        if(grid[row][j] == i)
            return false;
        else if(grid[j][col] == i)
            return false;
        else if(grid[3 * (row/3) + j / 3][3 * (col/3) + j % 3] == i)
            return false;
    }

    return true;
}

bool solve(int grid[9][9]) {
    for(int row = 0; row<9; row++){
        for(int col = 0; col<9; col++){
            if(grid[row][col] == 0){
                for(int i = 1; i<= 9; i++){
                    if(isSafe(i, grid, row, col)){
                        grid[row][col] = i;
                        if(solve(grid))
                            return true;
                        else
                            grid[row][col] = 0;
                    }
                }

                return false;
            }
        }
    }

    return true;;
}

int main(){
    int grid[9][9] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    cout << solve(grid) << endl;

    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
