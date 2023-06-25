#include <iostream>
#include <vector>
using namespace std;

void anotherApproach(int arr[], int n) {
    //Only if n is even
    //which means positives and negatives are equal to n/2

    vector<int> ans (n, 0);
    int posIndex = 0;
    int negIndex = 1;

    for(int i = 0; i<n; i++){
        if(arr[i] < 0) {
            ans[negIndex] = arr[i];
            negIndex+=2;
        }
        else {
            ans[posIndex] = arr[i];
            posIndex+=2;
        }
    }

    for(auto i : ans)
        cout << i << " ";
    cout << endl;
}

int main()
{
    int arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2};
    int n = sizeof(arr) / sizeof(int);

    vector<int> pos;
    vector<int> neg;

    for(int i = 0; i<n; i++){
        if(arr[i] >= 0)
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    }

    if(pos.size() > neg.size()){
        for(int i = 0; i<neg.size(); i++){
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }

        int index = 2 * neg.size();
        for(int i = neg.size(); i<pos.size(); i++) {
            arr[index] = pos[i];
            index++;
        }
    } else {
        for(int i = 0; i<pos.size(); i++){
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }

        int index = 2 * pos.size();
        for(int i = pos.size(); i<neg.size(); i++){
            arr[index] = neg[i];
            index++;
        }
    }

    for(int i = 0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
