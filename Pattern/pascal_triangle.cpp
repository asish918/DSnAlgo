#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > generatePascal(int numRows){
    vector<vector<int> > r(numRows);
    
    for(int i = 0; i<numRows; i++){
        r[i].resize(i+1);
        r[i][0] = 1;
        r[i][i] =  1;

        for(int j = 1; j<i; j++){
            r[i][j] = r[i-1][j-1] + r[i-1][j];
        }
    }

    return r;
}

int main(){
    int numRows = 5;

   vector<vector<int> > ans;
   ans = generatePascal(numRows);

   for(auto i : ans){
       for(auto j : i){
           cout << j << " ";
       }
       cout << endl;
   }
}
