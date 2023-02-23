#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int answer = 0;
    int w = 0, h = 0;
    for(auto size : sizes) {
        w = max(w, min(size[0], size[1]));
        h = max(h, max(size[0], size[1]));
    }
    answer = w * h;

    return answer;
}
