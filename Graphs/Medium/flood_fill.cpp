#include<iostream>
using namespace std;

void dfs(int row, int col, int ans[3][3], int image[3][3], int drow[], int dcol[], int initColor, int newColor){
    ans[row][col] = newColor;

    for(int i = 0; i<4; i++){
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if(nrow >= 0 && nrow < 3 && ncol >= 0 && ncol < 3 && image[nrow][ncol] == initColor && ans[nrow][ncol] != newColor)
            dfs(nrow, ncol, ans, image, drow, dcol, initColor, newColor);
    }
}

int main(){
    int image[3][3] = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    
    int ans[3][3];

    for(int i = 0; i<3; i++)
        for(int j = 0; j<3; j++)
            ans[i][j] = image[i][j];

    int initColor = image[1][1];
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    dfs(1, 1, ans, image, drow, dcol, initColor, 2);

    for(int i = 0; i<3; i++){
       for(int j = 0; j<3; j++)
           cout << ans[i][j] << " ";
       cout << endl;
    }
    return 0;
}
