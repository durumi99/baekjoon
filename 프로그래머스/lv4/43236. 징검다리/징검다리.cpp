#include <bits/stdc++.h>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    
    int left = 1;
    int right = distance; 
    int mid;
    
    while(left <= right) {
        mid = (left + right) / 2; // 거리의 최솟값 : mid
        int cnt = 0, prev = 0;
        
        for(int i = 0 ; i < rocks.size() ; i++) {
            if(rocks[i] - prev < mid) {
                cnt++;
            } else {
                prev = rocks[i];
            }
        }
        if(distance - prev < mid)   // 마지막 바위와 도착지점까지의 거리 체크
            cnt++;
        
        if(cnt <= n) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return answer;
}
