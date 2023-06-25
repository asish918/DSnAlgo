#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//TC - O(n + m)
//SC - O(n + m)
void bruteForce(vector<int> arr1, vector<int> arr2){
    int n = arr1.size();
    int m = arr2.size();

    vector<int> arr3(n + m);

    int index1 = 0;
    int index2 = 0;
    int index3 = 0;
    while(index1 < n && index2 < m){
        if(arr1[index1] <= arr2[index2]){
            arr3[index3] = arr1[index1];
            index1++;
            index3++;
        }
        else if(arr2[index2] < arr1[index1]){
            arr3[index3] = arr2[index2];
            index3++;
            index2++;
        }
    }

    while(index1 < n)
        arr3[index3++] = arr1[index1++];
    while(index2 < m)
        arr3[index3++] = arr2[index2++];

    for(auto i : arr3)
        cout << i << " ";
    cout << endl;
}

//Without extra space, just keep the ordered elements in the two arrays itself
void optimal1(vector<int>& arr1, vector<int>& arr2){
    int n = arr1.size();
    int m = arr2.size();

    int index1 = n - 1; //compare the greatest element of arr1 with smallest element of arr2
    int index2 = 0;
    while(index1 >= 0 && index2 < m){
        if(arr1[index1] > arr2[index2]){
            int temp = arr1[index1];
            arr1[index1] = arr2[index2];
            arr2[index2] = temp;
            index1--;
            index2++;
        }
        else
            break;
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    for(auto i : arr1)
        cout << i << " ";
    
    cout << endl;

    for(auto j : arr2)
        cout << j << " ";
    cout << endl;
}

void swapIfGreater(vector<int>& arr1, vector<int>& arr2, int index1, int index2){
    if(arr1[index1] > arr2[index2]){
        int temp = arr1[index1];
        arr1[index1] = arr2[index2];
        arr2[index2] = temp;
    }
}

void optimal2(vector<int>& arr1, vector<int>& arr2){
    int n = arr1.size();
    int m = arr2.size();

    int len = n + m;
    int gap = (len/2) + (len%2);

    while(gap > 0){
        int left = 0;
        int right = left + gap;

        while(right < len){
            //Both pointers in arr1 and arr2
            if(left < n && right >= n){
                swapIfGreater(arr1, arr2, left, right - n); //n - right to adjust index for arr2
            }
            //Both pointers in arr2
            else if(left >= n){
                swapIfGreater(arr1, arr2, left - n, right - n);
            }
            //Both pointers in arr1
            else{
                swapIfGreater(arr1, arr2, left, right);
            }
            left++, right++;
        }
        if(gap == 1) break;
        gap = (gap/2) + (gap%2);
    }

    for(auto i : arr1)
        cout << i << " ";
    cout << endl;
    for(auto j : arr2)
        cout << j << " ";
    cout << endl;
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {0, 2, 6, 8, 9};

    //bruteForce(arr1, arr2);
    //optimal1(arr1, arr2);
    optimal2(arr1, arr2);

    return 0;
}
