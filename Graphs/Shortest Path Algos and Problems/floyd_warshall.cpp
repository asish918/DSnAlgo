#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void floyd_warshall(vector<vector<int>>& matrix){
    int size = matrix.size();

    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
            if(matrix[i][j] == -1)
                matrix[i][j] = 1e9;
            if(i == j)
                matrix[i][j] = 0;
        }
    }

    for(int k = 0; k<size; k++){
        for(int i = 0; i<size; i++){
            for(int j = 0; j<size; j++){
                matrix[i][j] = min(matrix[i][j], (matrix[i][k] + matrix[k][j]));
            }
        }
    }

    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {0, 1, 43},
        {1, 0, 6},
        {-1, -1, 0}       
    };

    floyd_warshall(matrix);
    return 0;
}
