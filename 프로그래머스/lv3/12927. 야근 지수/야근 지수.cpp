#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    sort(works.begin(), works.end(), greater<>());
    int maxV = works[0];
    int cur = 0;
    
    while(n--) {
        if(works[cur] == 0)
            break;
        
        works[cur]--;
        if(cur == works.size()-1 || works[cur+1] <= works[0]) {
            cur = 0;
        } else {
            cur++;
        }
    }
    
    for(auto work : works) {
        answer += work * work;
    }
    return answer;
}
