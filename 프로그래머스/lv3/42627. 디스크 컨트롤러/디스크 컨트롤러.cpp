#include <bits/stdc++.h>

#define pp pair <int, int>
using namespace std;

struct cmp {
    bool operator()(pp a, pp b) {
        return a.second > b.second;
    }
};

priority_queue <pp, vector<pp>, cmp > pq;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    // for(auto job : jobs) {
    //     pq.push({job[1], job[0]});
    // }
    
    int curTime = 0;
    int cnt = 0;
    sort(jobs.begin(), jobs.end());
    
    while(cnt < jobs.size() || !pq.empty()) {
        if(cnt < jobs.size() && jobs[cnt][0] <= curTime) {
            pq.push({jobs[cnt][0], jobs[cnt][1]});
            cnt++;
            continue;
        } 
        
        if(!pq.empty()) {
            curTime += pq.top().second;
            answer += curTime - pq.top().first;
            pq.pop();
        } else {
            curTime = jobs[cnt][0];
        }
    }
    answer /= jobs.size();
    return answer;
}