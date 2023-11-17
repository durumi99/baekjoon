#include <bits/stdc++.h>
#define MAX 50001
#define INF 1e9
using namespace std;
pair <int, int> ansCandidate = {INF, INF};
vector < pair<int, int> > nodes[MAX];
vector <int> gates, summits;
int n;

// void updateAns(pair <int, int> p) {
//     if(ans.second > p.second) {
//         ans = p;
//     } else if(ans.second == p.second && ans.first > p.first) {
//         ans = p;
//     }
//     // ansCanidate = min(ansCandia)
// }

void getShortestPath() {
    int dist[MAX] = {0, };
    for(int i = 1 ; i <= n ; i++)
        dist[i] = INF;
    int isSummit[MAX] = {0, };
    
    for(auto summit : summits) {
        isSummit[summit] = 1;
    }
    priority_queue < pair <int, int> > pq;
    for(auto gate : gates) {
        pq.push({0, gate});
        dist[gate] = 0;
    }
    
    
    while(!pq.empty()) {
        int curIntensity = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(dist[cur] < curIntensity)
            continue;
        if(isSummit[cur])
            continue;
        
        for(int i = 0 ; i < nodes[cur].size() ; i++) {
            int nextIntensity = max(curIntensity, nodes[cur][i].first);
            int nextNode = nodes[cur][i].second;
            // if(dist[nextNode] == -1)
            //     continue;
            if(nextIntensity < dist[nextNode]) {
                dist[nextNode] = nextIntensity;
                if(!isSummit[nextNode])
                    pq.push({-nextIntensity, nextNode});
            }
        }
    }
    
    // return dist[end];
    for(auto summit : summits) {
        // ansCandidate.push_back({dist[summit], summit});
        ansCandidate = min(ansCandidate, {dist[summit], summit});
    }
}

vector<int> solution(int _n, vector<vector<int>> paths, vector<int> _gates, vector<int> _summits) {
    vector<int> answer;
    n = _n;
    gates = _gates;
    summits = _summits;
    // 다익스트라
    // start : gates
    // end : summits
    // 가장 짧은 intensity
    
    for(auto path : paths) {
        int x = path[0];
        int y = path[1];
        int cost = path[2];
        nodes[x].push_back({cost, y});
        nodes[y].push_back({cost, x});
    }
    for(int i = 1 ; i <= n ; i ++) {
        sort(nodes[i].begin(), nodes[i].end());
    }   
    getShortestPath();
    // 
    // for(auto gate : gates) {
    //     getShortestPath(gate);
    // }
    // sort(ansCandidate.begin(), ansCandidate.end());
    // answer.push_back(ansCandidate[0].second);
    // answer.push_back(ansCandidate[0].first);  
    answer.push_back(ansCandidate.second);
    answer.push_back(ansCandidate.first);
    return answer;
}