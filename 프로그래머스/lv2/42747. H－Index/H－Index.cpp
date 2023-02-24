#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    int answer = citations.size();
    
    while(answer) {
        
        int cnt[2] = {0, 0};
        for(int it : citations) {
            if(it >= answer) {
                cnt[0]++;
            }
            if(it <= answer) {
                cnt[1]++;
            }
        }
        if(cnt[0] >= answer && cnt[1] <= answer)
            break;
        answer--;
    }
    return answer;
}