#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
vector <vector<int>> orders;

void makeOrder(vector<int> order, int remain, int idx) {
    if(remain <= 0) {
        orders.push_back(order);
        return;
    }
    
    for(int i = idx ; i < order.size() ; i++) {
        order[i]++;
        makeOrder(order, remain - 1, i);
        order[i]--;
    }
}

int getWaitTime(vector <int> order, vector<vector<int>> reqs) {
    int waitTime = 0;
    priority_queue <int, vector<int>, greater<int>> pq[order.size()];
    
    for (int i = 1 ; i < order.size() ; i++) {
        for (int j = 0 ; j < order[i] ; j++) {
            pq[i].push(0);
        }
    }
    
    for (auto req : reqs) {
        int a = req[0];
        int b = req[1];
        int c = req[2];
        int picked = pq[c].top();
        pq[c].pop();
        
        if (picked > a) {
            waitTime += picked - a;
            pq[c].push(picked + b);
        } else if(picked < a) {
            pq[c].push(a + b);
        } else {
            pq[c].push(picked + b);
        }
    }
    
    return waitTime;
}
int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = INF;
    vector <int> order(k + 1, 1);
    makeOrder(order, n - k, 1);
    
    for (auto order : orders) {
        answer = min(answer, getWaitTime(order, reqs));
    }
    
    return answer;
}
