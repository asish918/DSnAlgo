#include<iostream>
#include<vector>
using namespace std;

int distributeCandies(int ratings[], int n) {
    if (n == 0)
        return 0;

    vector<int> candies(n, 1);

    for(int i = 1; i<n; i++)
        if(ratings[i] > ratings[i - 1])
            candies[i] = candies[i - 1] + 1;

    for(int i = n - 2; i>=0; i--)
        if(ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1])
            candies[i] = candies[i + 1] + 1;
    
    int totalCandies = 0;
    for(auto i : candies)
        totalCandies+=i;

    return totalCandies;
}

int main() {
    int ratings[] = {1, 0, 2};
    int N = sizeof(ratings) / sizeof(int);

    cout << distributeCandies(ratings, N) << endl;

    return 0;
}

/*
The distributeCandies function takes a reference to a vector of ratings as a parameter.

The function first checks if the number of children n is equal to 0. If true, it means there are no children, so no candies are required. In such cases, it returns 0.

A vector candies is initialized with size n, and each element is set to 1 as each child must have at least one candy.

The function traverses the ratings array from left to right. If the current child's rating is higher than the previous child's rating, it assigns one more candy than the previous child.

After the first traversal, the function traverses the ratings array from right to left. If the current child's rating is higher than the next child's rating and the current child has fewer or the same number of candies as the next child, it assigns one more candy than the next child. This is because we want to minimise candies given and don't want to unnecesarily give extra when they already have more candies.

Finally, the function calculates the total number of candies by summing up all the elements in the candies array.

In the main function, an example usage of the distributeCandies function is demonstrated. An array of ratings is initialized, and the minimum number of candies required is printed to the console.

*/
