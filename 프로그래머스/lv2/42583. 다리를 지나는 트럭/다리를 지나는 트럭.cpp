#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    // sort(truck_weights.begin(), truck_weights.end());
    int curWeight = 0;
    queue <int> q;
    int i = 0;
    
    while(true) { 
        if(q.size() == bridge_length) {
            curWeight -= q.front();
            q.pop();
        }
        if(i < truck_weights.size() && (curWeight + truck_weights[i]) <= weight) {
            q.push(truck_weights[i]);
            curWeight += truck_weights[i];
            i++;
        } else {
            q.push(0);
        }
        if(curWeight == 0){
            break;
        }
        
        answer++;
    }
    answer++;
    return answer;
}