#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int order = 1;
    int maxImportance = -1;
    // priority_queue < pair<int, int> > pq;
    queue < pair<int, int> > q; 
    for(int i = 0 ; i < priorities.size() ; i++) {
        q.push({priorities[i], i});
        maxImportance = max(priorities[i], maxImportance);
    }
    
    while(!q.empty()) {
        
        int curImportance = q.front().first;
        int curLocation = q.front().second;
        q.push({curImportance, curLocation});
        q.pop();
        
        while(!q.empty()) {
            int tmpImp = q.front().first;
            int tmpLoc = q.front().second;
            
            if(curImportance < tmpImp) {
                curImportance = tmpImp;
                curLocation = tmpLoc;
            } else if(curImportance == tmpImp && curLocation == tmpLoc) {
                break;
            }
            q.push({tmpImp, tmpLoc});
            q.pop();
        }
        // cout << curImportance << ' ' << curLocation << ' ' << order <<'\n';
        // curImportance = q.front().first;
        // curLocation = q.front().second;
        if(curLocation == location) {
            answer = order;
            // break;
        }
        q.pop();
        order++;
    }
    return answer;
}