#include <bits/stdc++.h>

using namespace std;

int root[101];

int find(int x) {
    if(x == root[x])
        return x;
    
    return root[x] = find(root[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    
    if(x == y)
        return;
    
    root[max(x, y)] = min(x, y);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for(int i = 1 ; i <= n ; i++)
        root[i] = i;
    
    priority_queue < pair <int, pair<int, int>>, vector<pair <int, pair<int, int>>>, greater<> > pq;
    for(auto cost : costs) {
        pq.push({cost[2], {cost[0], cost[1]}});
    }
    while(!pq.empty()) {
        int curCost = pq.top().first;
        int curNodeA = pq.top().second.first;
        int curNodeB = pq.top().second.second;
        pq.pop();
        
        if(find(curNodeA) == find(curNodeB))         
            continue;
        
        merge(curNodeA, curNodeB);    
        answer += curCost;
        
        bool check = true;
        for(int i = 1 ; i <= n ; i++) {
            if(find(i) != find(1)) {
                check = false;
                break;
            }
        }
        if(check)
            break;
    }
    return answer;
}