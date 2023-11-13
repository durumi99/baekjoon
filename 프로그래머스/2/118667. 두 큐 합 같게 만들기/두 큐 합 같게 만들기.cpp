#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    long sum1 = 0, sum2 = 0;
    queue <int> q1, q2;
    for(int i = 0 ; i < queue1.size() ; i++) {
        sum1 += queue1[i];
        sum2 += queue2[i];
        q1.push(queue1[i]);
        q2.push(queue2[i]);
    }
    long sum = (sum1 + sum2);
    int cnt = 0;
    
    while(sum1 != sum / 2 && cnt <= queue1.size() * 3) {
        if(sum1 > sum2) {
            int tmp = q1.front();
            q1.pop();
            q2.push(tmp);
            sum1 -= tmp;
            sum2 += tmp;
        } else {
            int tmp = q2.front();
            q2.pop();
            q1.push(tmp);
            sum2 -= tmp;
            sum1 += tmp;
        }
        cnt++;
    }
    if(cnt >= queue1.size() * 3) {
        answer = -1;
    } else {
        answer = cnt;
    }
    
    return answer;
}