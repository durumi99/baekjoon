#include <bits/stdc++.h>

#define MAX 10001
using namespace std;
vector<string> answer;
int visited[MAX];
int n;
bool visitAll() {
    for(int i = 0 ; i < n ; i++) {
        if(!visited[i])
            return false;
    }
    return true;
}
void dfs(vector<string> cur, vector<vector<string>> tickets) {
    if(visitAll()) {
        if(answer.empty() || answer > cur)
            answer = cur;
        return;
    }
    for(int i = 0 ; i < n ; i++) {
        if(tickets[i][0] == cur.back() && !visited[i]) {
            cur.push_back(tickets[i][1]);
            visited[i] = 1;
            dfs(cur, tickets);
            cur.pop_back();
            visited[i] = 0;
        }
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> cur;
    cur.push_back("ICN");
    n = tickets.size();
    sort(tickets.begin(), tickets.end());
    dfs(cur, tickets);
    return answer;
}