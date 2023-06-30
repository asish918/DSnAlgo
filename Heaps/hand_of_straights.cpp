#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

bool isNStraightHand(int hand[], int n, int groupSize){
    if(n % groupSize != 0)
        return false;

    unordered_map<int, int> m;
    priority_queue<int, vector<int>, greater<int> > q;

    for(int i = 0; i<n; i++)
        m[hand[i]]++;

    for(auto i : m)
        q.push(i.first);

    while(!q.empty()){
        int top = q.top();
        
        for(int i = top; i<top+groupSize; i++){
            if(m.find(i) == m.end())
                return false;

            m[i]--;
            if(m[i] == 0){
                if(i != q.top())
                    return false;
                q.pop();
            }
        }
    }

    return true;
}

int main(){
    int hand[] = {1, 2, 3, 4, 5};
    int n = sizeof(hand) / sizeof(int);
    int groupSize = 4;

    cout << isNStraightHand(hand, n, groupSize);

    return 0;
}

/*
The function isNStraightHand takes three parameters: hand, which is an array of integers representing the cards in hand; n, which is the number of cards in the hand; and groupSize, which represents the size of each group that the cards need to form.

The first check if (n % groupSize != 0) ensures that the number of cards is divisible by the group size. If not, it means it is impossible to form groups of the specified size, so the function returns false.

An unordered map m is used to count the frequency of each card in the hand. The loop iterates through the cards array and increments the count for each card encountered.

A min heap (priority_queue<int, vector<int>, greater<int> > q) is used to store the distinct cards from the hand in ascending order. The cards are pushed into the min heap using a loop over the elements of the unordered map m. By using a min heap, we ensure that the smallest available card is always at the top.

The main loop continues until the min heap q is empty. It checks if the hand can form groups of the specified size.

In each iteration of the main loop, the smallest available card from the min heap is obtained using q.top() and stored in the variable top.

A nested loop iterates groupSize times, starting from top. It checks if each card in the group is present in the frequency map m. If any card is missing, it means the hand cannot form a group of the specified size, so the function returns false.

If a card is present, its count in the map m is decremented by 1 to indicate that it has been used. If the count becomes 0, it means that card is fully used, so it is removed from the map and the min heap.

After the nested loop finishes, it means a valid group of the specified size has been formed using the current smallest card. The loop continues to check for the next group using the next smallest card in the min heap.

If the min heap q becomes empty, it means all the groups have been successfully formed, so the function returns true.

The intuition behind this implementation is to use a min heap to maintain the available cards in ascending order. The nested loop checks for the formation of valid groups by iterating through each card in the group and verifying its presence and count in the frequency map m. By decrementing the counts and removing fully used cards from the map and min heap, we ensure that each card is used only once in each group. If all groups can be formed, the function returns true, otherwise false.
*/
