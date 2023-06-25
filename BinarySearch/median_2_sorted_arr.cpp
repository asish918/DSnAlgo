#include <iostream>
#include<climits>
#include<algorithm>
using namespace std;

double median2SortedArr(int arr1[], int arr2[], int n, int m){
    if(n > m){
        return median2SortedArr(arr2, arr1, m, n);
    }

    int low = 0, high = n;

    while(low<=high){
        int cut1 = low + (high - low) / 2;
        int cut2 = (n + m + 1) / 2 - cut1;
        int l1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
        int r1 = (cut1 == n) ? INT_MAX : arr1[cut1];
        int r2 = (cut2 == m) ? INT_MAX : arr2[cut2];

        if(l1 <= r2 && l2 <= r1){
            if((n + m) % 2 == 0){
                return ((max(l1, l2) + min(r1, r2)) / 2.0);
            }
            else
                return max(l1, l2);
        }

        else if(l1 > r2){
            high = cut1 - 1;
        }

        else{
            low = cut1 + 1;
        }
    }
    return -1;
}

int main()
{
    int arr1[] = {4, 6};
    int arr2[] = {1, 2, 3, 5};
    // 1, 2, 3, 3, 4, 6, 7, 10, 12, 15
    int n = sizeof(arr1) / sizeof(int);
    int m = sizeof(arr2) / sizeof(int);
    
    cout << median2SortedArr(arr1, arr2, n, m) << endl;

    return 0;
}
