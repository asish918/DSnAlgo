#include <iostream>
#include <vector>
using namespace std;

void solve(int i, int j, string word, vector<vector<int>> grid, int n, int drow[], int dcol[], vector<string>& ans, vector<vector<int>>& vis){
    if(i == n - 1 && j == n - 1){
        ans.push_back(word);
        return;
    }

    string path = "DLRU";
    for(int index = 0; index < 4; index++){
        int nexti = i + drow[index];
        int nextj = j + dcol[index];

        if(nexti < n && nexti >= 0 && nextj < n && nextj >= 0 && !vis[nexti][nextj] && grid[nexti][nextj] == 1){
            vis[i][j] = 1;
            solve(nexti, nextj, word + path[index], grid, n, drow, dcol, ans, vis);
            vis[i][j] = 0;
        }
    }
}

int main() {
    vector<vector<int>> grid = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    int n = grid.size();
    vector<vector<int>> vis(n, vector<int>(n, 0));
    
    vector<string> ans;
    //DLRU
    int drow[] = {1, 0, 0, -1};
    int dcol[] = {0, -1, 1, 0};
    
    solve(0, 0, "", grid, n, drow, dcol, ans, vis);

    for(auto it : ans)
        cout << it << endl;
    return 0;
}
