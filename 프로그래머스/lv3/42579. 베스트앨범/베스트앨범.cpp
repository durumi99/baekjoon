#include <bits/stdc++.h>

using namespace std;
bool cmp(pair <string, int> a, pair <string, int> b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    
    return b.second < a.second;
}

bool cmp2(pair <int, int> a, pair <int, int> b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }
    
    return a.first > b.first;
}
map <string, int> streams;
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for(int i = 0 ; i < genres.size() ; i++) {
        streams[genres[i]] += plays[i];
    }
    vector < pair<string, int> > v (streams.begin(), streams.end());
    sort(v.begin(), v.end(), cmp);
    
    // string album[2] = {v[0].first , v[1].first};
    
    for(auto it : v) {
        vector < pair<int, int> > vv;
        for(int j = 0 ; j < genres.size() ; j++) {
            if(genres[j] == it.first)
                vv.push_back({plays[j], j});
        }
        
        sort(vv.begin(), vv.end(), cmp2);
        int len = min(2, (int)vv.size());
        for(int j = 0 ; j < len ; j++) {
            answer.push_back(vv[j].second);
        }
        // vv.clear();
        // for(auto it : vv) {
        //     cout << it.first << ' ' << it.second << '\n';
        // }
        // cout << '\n';
    }
    return answer;
}