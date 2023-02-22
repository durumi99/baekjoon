#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    answer = n - lost.size();
    sort(lost.begin(), lost.end());
    sort(reserve.begin(),reserve.end());
    
    for(int i = 0 ; i < lost.size(); i++) {
        auto found = find(reserve.begin(), reserve.end(), lost[i]);
        
        if(found != reserve.end()) {
            reserve.erase(found);
            lost.erase(lost.begin()+i);
            i--;
            answer++;
        }
    }
    for(int i = 0 ; i < lost.size(); i++) {
        auto found = find(reserve.begin(), reserve.end(), lost[i]-1);
        
        if(found != reserve.end()) {
            reserve.erase(found);
            answer++;
            continue;
        }
        
        found = find(reserve.begin(), reserve.end(), lost[i]+1);
        
        if(found != reserve.end()) {
            reserve.erase(found);
            answer++;
            continue;
        }
        
    }
    
    return answer;
}
