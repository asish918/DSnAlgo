#include <iostream>
#include <vector>
using namespace std;

void markRow(vector<vector<int>>& arr, int i){
    for(int j = 0; j<arr[0].size(); j++){
        if(arr[i][j] != 0)
            arr[i][j] = -1;
    }
}

void markCol(vector<vector<int>>& arr, int j){
    for(int i = 0; i<arr.size(); i++){
        if(arr[i][j] != 0)
            arr[i][j] = -1;
    }
}

void bruteForce(vector<vector<int>>& arr){
    int n = arr.size();
    int m = arr[0].size();

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(arr[i][j] == 0){
                markRow(arr, i);
                markCol(arr, j);
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++)
            if(arr[i][j] == -1)
                arr[i][j] = 0;
    }

    for(auto i :  arr){
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

void betterApproach(vector<vector<int>> arr){
    int n = arr.size();
    int m = arr.size();

    int row[n] = {0};
    int col[m] = {0};

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(arr[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(row[i] || col[j])
                arr[i][j] = 0;
        }
    }

    for(auto i : arr){
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

void optimalApproach(vector<vector<int>> arr){
    int n = arr.size();
    int m = arr[0].size();

    bool fr = false;
    bool fc = false;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(arr[i][j] == 0){
                if(i == 0) fr = true;
                if(j == 0) fc == true;
                arr[i][0] = 0;
                arr[0][j] = 0;
            }
        }
    }

    for(int i = 1; i<n; i++){
        for(int j = 1; j<m; j++){
            if(arr[i][j] != 0)
                if(arr[i][0] == 0 || arr[0][j] == 0)
                    arr[i][j] = 0;
        }
    }

    if(fr){
        for(int j = 0; j<m; j++)
            arr[0][j] = 0;
    }

    if(fc)
        for(int i = 0; i<n; i++)
            arr[i][0] = 0;

    for(auto i : arr){
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> arr = {
        {1, 2, 3, 4},
        {5, 6, 0, 7},
        {8, 9, 4, 6},
        {8, 4, 5, 2}
    };
    
    //TC - (O(n * m)(n + m) + O(n * m)) ~ (O(n^3))
    //bruteForce(arr);

    //TC - (O(n * m) + O(n * m)) ~ O(2 * n * m)
    //SC - (O(n) + O(m))
    //betterApproach(arr);
    
    //TC - (O(n * m) + O(n * m)) ~ O(2 * n * m)
    //SC - (O(1))
    optimalApproach(arr);
}
