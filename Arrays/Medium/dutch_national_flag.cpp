#include<iostream>
using namespace std;

int main() {
    int nums[] = {2, 0, 2, 1, 1, 0};
    int low = 0;
    int mid = 0;
    int high = sizeof(nums) / sizeof(int);
    int i = 0;

    while (mid<=high)
    {
        switch(nums[mid]) {
            case 0:
                swap(nums[mid++], nums[low++]);
                break;
            
            case 1:
                mid++;
                break;
            
            case 2:
                swap(nums[mid], nums[high--]);
                break;
        }
        i++;
    }
    
    for(i = 0; i<sizeof(nums) / sizeof(int); i++)
        cout << nums[i] << " ";
    return 0;
}