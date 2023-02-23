#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue <int> q;
    queue <int> speedQ;
    
    for(int i = 0 ; i < speeds.size() ; i++) {
        q.push(progresses[i]);
        speedQ.push(speeds[i]);
    }

    while(!q.empty()) {
        int cnt = 0;
        
        while(!q.empty() && q.front() >= 100) {
            cnt++;
            q.pop();
            speedQ.pop();
        }
        
        if(cnt > 0) {
            answer.push_back(cnt);
            cout << cnt << ' ';
        }
        
        int qSize = q.size();
        for(int i = 0 ; i < qSize ; i++) {
            int curQ = q.front();
            q.pop();
            int curSpeedQ = speedQ.front();
            speedQ.pop();
            
            q.push(curQ + curSpeedQ);
            speedQ.push(curSpeedQ);
        }
    }
    return answer;
}