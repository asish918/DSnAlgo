#include <iostream>
#include <vector>
using namespace std;

void bruteForce(vector<vector<int>> matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    int coordinates[2] = {-1, -1};

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            bool flag = true;
            for(int k = 0; k < 4; k++) {
                int nexti = i + drow[k];
                int nextj = j + dcol[k];

                if(nexti >= 0 && nexti < n && nextj >= 0 && nextj < m && matrix[nexti][nextj] > matrix[i][j])
                    flag = false;
            }

            if(flag){
                coordinates[0] = i;
                coordinates[1] = j;
            }
            
        }
    }

    cout << coordinates[0] << " " << coordinates[1] << endl;
}

int main() {
    vector<vector<int>> matrix = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32},
    };

    bruteForce(matrix);
    return 0;
}
