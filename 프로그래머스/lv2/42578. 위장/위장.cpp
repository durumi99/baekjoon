#include <bits/stdc++.h>

using namespace std;

map <string, int > m;

int dfs(vector < pair<string, int> > v, int idx, int sum) {
    if(idx == v.size()) {
        return sum;
    }
    
    return dfs(v, idx+1, sum * v[idx].second) + dfs(v, idx+1, sum);
}
int solution(vector<vector<string>> clothes) {
    int answer = 0;
    for(auto cloth : clothes) {
        m[cloth[1]]++;
    }
    vector < pair<string, int> > v (m.begin(), m.end());
    answer = 1;
    for(auto it : v) {
        answer *= it.second+1;
    }
    answer--;
    return answer;
}