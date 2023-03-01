#include <bits/stdc++.h>

// #define MAX 5*5*5*5*5+1
using namespace std;

char c[5] = {'A', 'E', 'I', 'O', 'U'};

int idx = 0;
int answer;

void dfs(string cur, string word) {
    if(cur.length() > 5) {
        return;
    }
    if(cur == word) {
        answer = idx;
    }
    // cout << idx << ' ' << cur << '\n';
    idx++;
    for(int i = 0 ; i < 5 ; i++) {
        dfs(cur + c[i], word);
    }
}

int solution(string word) {
    // int answer = 0;
    // int idx = 0;
    dfs("", word);
    return answer;
}