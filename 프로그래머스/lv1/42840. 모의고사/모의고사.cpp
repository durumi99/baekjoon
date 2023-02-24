#include <bits/stdc++.h>

using namespace std;
vector <int> v[3] = {{1, 2, 3, 4, 5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int points[3] = {0, };
    
    for(int i = 0 ; i < answers.size() ; i++) {
        for(int j = 0 ; j < 3 ; j++) {
            if(answers[i] == v[j][i % v[j].size()])
                points[j]++;
        }
    }
    int maxPoint = *max_element(points, points+3);
    for(int i = 0 ; i < 3 ; i++) {
        if(points[i] == maxPoint)
            answer.push_back(i+1);
    }
    sort(answer.begin(), answer.end());
    return answer;
}