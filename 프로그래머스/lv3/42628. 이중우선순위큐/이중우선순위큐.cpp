#include <bits/stdc++.h>

using namespace std;
priority_queue < int, vector<int>, greater<int> > pq1; // 최솟값
priority_queue < int > pq2; // 최댓값

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector <int> v;
    for(auto op : operations) {
        if(op[0] == 'I') {
            v.push_back(stoi(op.substr(1)));
        } else if(v.empty()) {
            continue;
        }
        
        if(op == "D 1") { // 최댓값 삭제
            v.erase(max_element(v.begin(), v.end()));
        } else if(op == "D -1"){
            // cout << *min_element(v.begin(), v.end()) << '\n';
            v.erase(min_element(v.begin(), v.end()));
        }
    }
    if(v.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        answer.push_back(*max_element(v.begin(), v.end()));
        answer.push_back(*min_element(v.begin(), v.end()));
    }
    return answer;
}