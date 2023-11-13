#include <bits/stdc++.h>

using namespace std;
char personalityTypes[4][2] = {{'R', 'T'},{'C', 'F'},{'J', 'M'},{'A', 'N'} };
string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int len = survey.size();
    int personality[4] = {0, };
    for(int i = 0 ; i < len ; i++) {
        if(survey[i] == "RT") {
            personality[0] += choices[i] - 4;
        } else if(survey[i] == "TR") {
            personality[0] -= choices[i] - 4;
        } else if(survey[i] == "CF") {
            personality[1] += choices[i] - 4;
        } else if(survey[i] == "FC") {
            personality[1] -= choices[i] - 4;
        } else if(survey[i] == "JM") {
            personality[2] += choices[i] - 4;
        } else if(survey[i] == "MJ") {
            personality[2] -= choices[i] - 4;
        } else if(survey[i] == "AN") {
            personality[3] += choices[i] - 4;
        } else if(survey[i] == "NA") {
            personality[3] -= choices[i] - 4;
        } 
    }
    
    for(int i = 0 ; i < 4 ; i++) {
        // cout << personality[i] << ' ';
        if(personality[i] <= 0) {
            answer.push_back(personalityTypes[i][0]);
        } else {
            answer.push_back(personalityTypes[i][1]);
        }
    }
    return answer;
}