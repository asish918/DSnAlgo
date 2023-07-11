#include<iostream>
#include<unordered_set>
#include<utility>
#include<queue>
using namespace std;

int wordLadderLength(string startWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    queue<pair<string, int>> q;
    
    q.push({startWord, 1});
    wordSet.erase(startWord);

    while(!q.empty()) {
        auto it = q.front();
        q.pop();

        string word = it.first;
        int steps = it.second;

        if(word == endWord) return steps;
        
        for(int i = 0; i<word.length(); i++) {
            char original_char = word[i];

            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;

                if(wordSet.find(word) != wordSet.end()) {
                    q.push({word, steps + 1});
                    wordSet.erase(word);
                }
            }

            word[i] = original_char;
        }
    }

    return 0;
}

int main() {
    string startWord = "der";
    string endWord = "dfs";

    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};

    cout << wordLadderLength(startWord, endWord, wordList) << endl;

    return 0;
}
