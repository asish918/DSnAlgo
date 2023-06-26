#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct meeting {
    int start;
    int end;
    int pos;
};

bool cmp(struct meeting a, meeting b){
    if(a.end < b.end) return true;
    else if(a.end > b.end) return false;
    else if(a.pos < b.pos) return true;
    return false;
}

void nMeetingsOneRoom(int s[], int e[], int n){
    struct meeting meet[n];
    for(int i = 0; i<n; i++)
        meet[i].start = s[i], meet[i].end = e[i], meet[i].pos
             = i + 1;
    
    sort(meet, meet + n, cmp);

    vector<int> ans;

    int limit = meet[0].end;
    ans.push_back(meet[0].pos);

    for(int i = 1; i<n; i++){
        if(meet[i].start > limit){
            limit = meet[i].end;
            ans.push_back(meet[i].pos);
        }
    }

    for(int i = 0; i<ans.size(); i++)
        cout << ans[i] << " ";
}

int main(){
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start) / sizeof(int);

    nMeetingsOneRoom(start, end, n);
    return 0;
}
