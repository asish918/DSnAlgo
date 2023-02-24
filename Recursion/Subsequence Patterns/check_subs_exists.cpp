#include <iostream>
using namespace std;

bool check_subs(int index, int arr[], int n, int s, int sum){
    if(index == n){
        if(s == sum)
            return true;
        return false;
    }

    s+=arr[index];
    if(check_subs(index + 1, arr, n, s, sum))
        return true;

    s-=arr[index];
    if(check_subs(index + 1, arr, n, s, sum))
        return true;

    return false;
}

int main() {
    bool flag = 1;
    int sum = 3;
    int arr[] = {1, 1, 0};
    int n = sizeof(arr)/sizeof(int);

    flag = check_subs(0, arr, n, 0, sum);

    cout << flag << endl;

    return 0;
} 
