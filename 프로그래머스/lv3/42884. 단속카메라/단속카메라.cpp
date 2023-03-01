#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end());
    
    vector <pair<int, int>> v;
    for(auto route : routes) {
        if(v.empty() || route[0] > v.back().second) {
            v.push_back({route[0], route[1]});
        } else {
            v.back().first = route[0];
            v.back().second = min(route[1], v.back().second);
        }
    }
    // for(auto i : v) {
    //     cout << i.first << ' ' << i.second << '\n';
    // }
    answer = v.size();
    return answer;
}