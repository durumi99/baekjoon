#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    long long left = 1;
    long long right = (long long)times[times.size()-1] * n;
    long long mid;
    while(left <= right) {
        long long cnt = 0;
        mid = (left + right) / 2;
        for(int i = 0; i < times.size(); i++) {
            cnt += mid / times[i];
        }
        
        if(cnt < n) {
            left = mid + 1;
        } else {
            answer = mid;
            right = mid - 1;
        }
    }
    // answer = mid;
    return answer;
}