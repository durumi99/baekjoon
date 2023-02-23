#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 987654321;
    int w = -1;
    pair <int, int> wIdx;
    for(int i = 0 ; i < sizes.size() ; i++) {
        // w = max(w, sizes[i][0]);
        // w = max(w, sizes[i][1]);
        if(sizes[i][0] > w) {
            w = sizes[i][0];
            wIdx = {i, 0};
        }
        if(sizes[i][1] > w) {
            w = sizes[i][1];
            wIdx = {i, 1};
        }
    }
    int h = -1;
    for(int i = 0 ; i < sizes.size() ; i++) {
        if(i != wIdx.first || 0 != wIdx.second) {
            h = sizes[i][0];
            bool check = true;
            for(int j = 0 ; j < sizes.size(); j++) {
                if(sizes[j][0] <= w && sizes[j][1] <= h)
                    continue;
                if(sizes[j][0] <= h && sizes[j][1] <= w)
                    continue;
                check = false;
                break;
            }
            if(check)
                answer = min(answer, w * h);
        }
        
        if(i != wIdx.first || 1 != wIdx.second) {
            h = sizes[i][1];
            bool check = true;
            for(int j = 0 ; j < sizes.size(); j++) {
                if(sizes[j][0] <= w && sizes[j][1] <= h)
                    continue;
                if(sizes[j][0] <= h && sizes[j][1] <= w)
                    continue;
                check = false;
                break;
            }
            if(check)
                answer = min(answer, w * h);
        }
    }
    
    return answer;
}