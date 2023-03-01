#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(s < n) {
        answer.push_back(-1);
        return answer;
    }
    
    for(int i = 0 ; i < n ; i++)
        answer.push_back(s/n);
    if(s % n) {
        int res = s % n;
        for(int i = 0 ; i < res ; i++) {
            answer[i]++;
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}