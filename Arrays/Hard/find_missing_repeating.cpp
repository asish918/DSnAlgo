#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void bruteForce(vector<int> arr){
    int n = arr.size();
    vector<int> hash_table(n + 1, 0);

    for(int i = 0; i<n; i++){
        hash_table[arr[i]]++;
    }

    for(int i = 1; i<n+1; i++){
        if(hash_table[i] == 2)
            cout << "Repeating Value - " << i << endl;
        else if(hash_table[i] == 0)
            cout << "Missing Value - " << i << endl;
    }
}

void optimal(vector<int> arr){
    int n = arr.size();
    int sum = 0;
    int sum_of_squares = 0;

    for(int i = 0; i<n; i++){
        sum += arr[i];
        sum_of_squares = sum_of_squares + (arr[i] * arr[i]);
    }

    int S = (n * (n + 1))/2;    //Sum of n natural numbers
    int S2 = (n * (n + 1) * (2*n + 1))/6;   //Sum of squares of n natural numbers

    int eqn1 = S - sum;     //Missing number - Repeating Number = S - sum
    int eqn2 = (S2 - sum_of_squares)/eqn1;      //(Missing number - Repeating)^2 = S2 - sum_of_squares    //Dividing both equations to get (Missing NUmber + Repeating Number)
    
    int X = (eqn1 + eqn2)/2;
    int Y = X - eqn1;

    cout << X << " " << Y << endl;
}

int main(){
    vector<int> arr = {1, 3, 3};

    //Brute force 
    //TC - (O(2n))
    //SC - (O(n))
    bruteForce(arr);

    //Optimal
    //TC - (O(n))
    //SC - (O(1))
    optimal(arr);

    return 0;
}
