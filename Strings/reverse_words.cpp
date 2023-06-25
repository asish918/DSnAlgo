#include<iostream>
#include<algorithm>
using namespace std;

string approach2(string s) {
    reverse(s.begin(), s.end());

    int i = 0;
    int j = 0;
    int n = s.length();

    while (i < n) {
        while(i < n && s[i] == ' ')
            i++;
        j = i;
        while(j < n && s[j] != ' ')
            j++;
        reverse(s.begin() + i, s.begin() + j);
        i = j;
    }

    i = 0;
    j = 0;

    while(j < n) {
        while(j < n && s[j] == ' ')
            j++;

        while(j < n && s[j] != ' ')
            s[i++] = s[j++];

        if(j < n)
            s[i++] = ' ';
    }

    s.resize(i);

    return s;
}

string approach1(string s) {
    string res;
    int i = s.length();
    
    while(i >= 0) {
        while(i >= 0 && s[i] == ' ')
            i--;

        string word;
        while(i >= 0 && s[i] != ' ') {
            word = s[i] + word;
            i--;
        }

        if(!word.empty()) {
            if(!res.empty())
                res+=' ';
            res+=word;
        }
    }
    
    return res;
}

int main(){
    string s = "the sky is blue";
    
    cout << approach1(s) << endl;
   // cout << approach2(s) << endl;
    return 0;
}

/*
######Approach 2
First, we reverse the entire string using the reverse function from the <algorithm> library. This step ensures that the words are in the correct order, but each word is reversed.

We initialize two pointers i and j to keep track of the current word boundaries.

The first while loop is responsible for skipping any leading spaces. It continues until i reaches the end of the string or a non-space character is encountered.

Once we have the beginning of a word (pointed by i), we move j to the end of that word by scanning for the next space character or reaching the end of the string.

Now, we have the boundaries of the current word, so we reverse it using the reverse function again, but this time, we provide the range [i, j) to reverse only the characters of the word.

After reversing the word, we move i to the next word by setting it to the value of j.

We repeat steps 4-7 until we have processed all the words in the string.

Next, we remove any extra spaces by using two additional pointers i and j. These pointers help us copy non-space characters from j to i while skipping any consecutive spaces.

The second while loop skips any leading spaces until j reaches the end of the string or a non-space character is encountered.

Then, we copy the non-space characters from j to i until we reach the next space or the end of the string.

If j has not reached the end of the string, we add a single space character at i to separate the words.

We repeat steps 10-12 until we have processed all the characters in the string.

Once the loop is complete, we resize the string to the correct length by using the resize function and passing i as the new size. This step removes any trailing characters that are no longer part of the reversed words.

Finally, we reverse the entire string again using the reverse function to obtain the desired output, where the words are in reverse order, but each word is correctly oriented.

 */

/*
##### Approach 1
Initialize an empty string called result to store the reversed words.
Start traversing the input string s from right to left using the variable i, initialized to s.length() - 1.
Skip any leading spaces by decrementing i while the character at s[i] is a space.
Create an empty string called word to store each individual word.
While i is greater than or equal to 0 and the character at s[i] is not a space, concatenate s[i] with the front of the word string, and decrement i.
After extracting a complete word, check if word is not empty.
If result is not empty, append a single space to it.
Append the word to the result string.
Repeat steps 3-8 until all words in s have been processed.
Return the result string containing the reversed order of words with a single space between each word.
 */
