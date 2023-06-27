#include <iostream>
#include <vector>
using namespace std;

int numberOfSubstrings(string s){
    int a = 0, b = 0, c = 0;
    int count_substr = 0;

    int left = 0;
    int right = 0;
    int n = s.length();

    while(right < s.length()) {
        if(s[right] == 'a') a++;
        else if(s[right] == 'b') b++;
        else c++;

        while(a && b && c) {
            if(s[left] == 'a') a--;
            else if(s[left] == 'b') b--;
            else c--;

            left++;
        }

        count_substr += right - left + 1; 
        right++;
    }

    return n * (n + 1)/2 - count_substr;
}

int main(){
    string s = "abcabc";

    cout << numberOfSubstrings(s) << endl;

    return 0;
}

/*
The code initializes variables a, b, and c to keep track of the counts of characters 'a', 'b', and 'c', respectively.
It also initializes start to track the start index of the current substring, count to store the total count of substrings, and n to store the length of the string s.
The code iterates over the string s using the end variable as the end index of the current substring.
In each iteration, it checks the character at index end and updates the respective count variables a, b, or c.
The code then enters a while loop to shrink the substring from the left until it no longer contains all three characters 'a', 'b', and 'c'. The condition a && b && c ensures that all three counts are non-zero.
Inside the while loop, it checks the character at index start and decrements the respective count variable.
It increments the start index to move it to the right, effectively shrinking the substring.
After exiting the while loop, the code updates the count by adding the length of the current substring, which is end - start + 1.
Finally, the code calculates the number of substrings that do not contain all three characters by subtracting the count from the total number of possible substrings, which is (n * (n + 1)) / 2. The formula (n * (n + 1)) / 2 represents the sum of the first n natural numbers, which gives the count of all possible substrings of length 1 to n.
*/
