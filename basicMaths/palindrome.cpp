#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    string is_palindrome(int n){
        int flag = 0;
        vector<int> number;
        int count = 0;
        while(n) {
            int digit = n % 10;
            number.insert(number.begin(), digit);
            n = n / 10;
        }

        int left = 0;
        int right = number.size() - 1;
        while(left<=right){
             if(number[left] == number[right]){
                 left++;
                 right--;
             }

            else
                break;
        }

        if(left > right)
            flag = 1;

        if(flag) {
            return "Yes";
        } 
        else {
            return "No";
        }
    }
};

int main(){
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        Solution ob;
        string ans = ob.is_palindrome(n);
        cout << ans << endl;
    }
    
}