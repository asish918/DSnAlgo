#include<iostream>
using namespace std;

int main(){
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int n = sizeof(arr) / sizeof(int);
    int key = 10;

    int index = -1;

    int low = 0;
    int high = n - 1;
    int mid = low + (high - low) / 2;

    while(low<=high){
        mid = low + (high - low) / 2;
        if(arr[mid] == key){
            index = mid;
            break;
        }
        
        else if(arr[0] <= arr[mid]){
            if(key >= arr[0] && key <= arr[mid]){
                high = mid - 1;
            }
            
            else {
                low = mid + 1;
            }
        }

        else{
            if(key >= arr[mid] && key <= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }

    cout << index << endl;

    return 0;
}