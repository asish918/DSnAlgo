#include<iostream>
#include<algorithm>
using namespace std;

int arr[] = {12, 34, 67, 90};
int students = 2;

bool isAllocated(int bar){
    int allocated_stud = 1;
    int pages = 0;

    for(int i = 0; i<sizeof(arr) / sizeof(int); i++){
        if(bar < arr[i])
            return false;
        
        if((pages + arr[i]) > bar){
            allocated_stud += 1;
            pages = arr[i];
        }

        else {
            pages+=arr[i];
        }
    }

    if(allocated_stud > students)
        return false;
    else
        return true;
}

int main(){
    int low = arr[0];
    int high = 0;
    int res = -1;

    for(int i = 0; i<sizeof(arr) / sizeof(int); i++){
        high += arr[i];
        low = min(low, arr[i]);
    }

    while(low<=high){
        int mid  = low + (high - low) / 2;
        if(isAllocated(mid)){
            res = mid;
            high = mid - 1;
        }

        else
            low = mid + 1;
    }

    cout << res << endl;
    
    return 0;
}