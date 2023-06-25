#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<vector<int>> matrix = {
        {3, 30, 38},
        {36, 43, 60},
        {40, 51, 69},
    };

    int n = matrix.size();
    int m = matrix[0].size();

    int i = 0;
    int j = m - 1;
    int key = 43;

    while(i >= 0 && i < n && j >= 0 && j < m) {
        if(matrix[i][j] == key) {
            cout << "Gotcha at - " << i << " " << j << endl;
            return 0;
        }
        else if(matrix[i][j] > key)
            j--;
        else
            i++;
    }

    cout << "No such element" << endl;
    return 0;
}
