#include<iostream>
#include<vector>
using namespace std;

void findnCr(int n, int r){
    int res = 1;
    for(int i = 0; i<r; i++){
        res = res * (n - i);
        res = res/(i + 1);
    }

    cout << res << endl;
}

vector<int> printNthRow(int n){
    vector<int> ansRow;

    int ans = 1;

    ansRow.push_back(1);

    for(int i = 1; i<n; i++){
        ans = ans * (n - i);
        ans = ans / i;
        ansRow.push_back(ans);
    }

    return ansRow;
}

void printTriangle(int numRows){
    for(int i = 1; i<=numRows; i++){
        vector<int> temp;

        temp = printNthRow(i);
        for(auto j : temp)
            cout << j << " ";

        cout << endl;
    }
}

void printTriangleAlternate(int n){
    vector<vector<int>> triangle(n);

    for(int i = 0; i<n; i++){
        triangle[i].resize(i + 1);

        triangle[i][0] = triangle[i][i] = 1;

        for(int j = 1; j<i; j++){
            triangle[i][j] = (triangle[i-1][j-1] + triangle[i-1][j]);
        }
    }

    for(auto i : triangle){
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }
}

int main() {
    // Type 1 problem (print single element rth row and nth column)
    //findnCr(10, 3);
    

    // Type 2 problem (print nth row enitirely)
    //printNthRow(6);

    //Type 3 (Print entire pascal triangle)
    //printTriangle(5);
    printTriangleAlternate(5); //For GFG
    return 0;
}
