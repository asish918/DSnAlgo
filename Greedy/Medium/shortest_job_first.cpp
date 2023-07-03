#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int A[] = {4, 3, 7, 1, 2};
    int N = sizeof(A) / sizeof(int);

    sort(A, A + N);

    int curWt = 0;
    int cumWt = 0;
    for(int i = 1; i<N; i++) {
        curWt += A[i - 1];
        cumWt += curWt;
    }

    cout << cumWt / N << endl;


    //Calculated Waiting times
    //1 - 0
    //2 - 1
    //3 - 3
    //4 - 6
    //7 - 10

    //Dry run of the total caluclations
    //BT - curWt - totalWt
    //2 - 1 - 1
    //3 - 3 - 4
    //4 - 6 - 10
    //7 - 10 - 20
    return 0;
}

/*
The code declares an integer array A[] with some burst times of processes. The variable N is initialized with the size of the array, which is calculated by dividing the total size of A by the size of a single integer.

The code then sorts the array A in ascending order using the sort() function from the C++ standard library. Sorting the burst times in ascending order is a crucial step in the SJF algorithm as it ensures that the shortest job comes first.

Two variables curWt (current waiting time) and cumWt (cumulative waiting time) are initialized to 0. These variables will be used to calculate the waiting times of the processes.

The code enters a loop starting from i = 1 and continues until i reaches N. This loop iterates over the sorted array A and calculates the waiting time for each process.

Inside the loop, curWt is incremented by the burst time of the previous process (A[i - 1]). This represents the waiting time of the current process.

The waiting time of the current process is added to cumWt, which keeps track of the cumulative waiting time of all the processes.

After the loop, the code calculates the average waiting time by dividing cumWt by N, the total number of processes.

Finally, the average waiting time is printed to the console using cout.

In summary, the code sorts the burst times in ascending order and then calculates the average waiting time by summing up the waiting times of all the processes. The average waiting time is obtained by dividing the cumulative waiting time by the total number of processes.
*/
