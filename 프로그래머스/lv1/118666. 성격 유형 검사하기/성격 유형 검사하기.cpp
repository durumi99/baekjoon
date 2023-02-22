#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

map <char,int> m;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    m.insert({'R', 0});
    m.insert({'T', 0});
    m.insert({'C', 0});
    m.insert({'F', 0});
    m.insert({'J', 0});
    m.insert({'M', 0});
    m.insert({'A', 0});
    m.insert({'N', 0});

    for(int i = 0 ; i < survey.size() ; i++) {
        string cur = survey[i];
        int curChoice = choices[i];
        if(curChoice < 4){
            m[cur[0]] += 4-curChoice;
        } else if(curChoice > 4) {
            m[cur[1]] += curChoice-4;
        }
    }
    
    if(m['T'] > m['R']) {
        answer += 'T';
    } else {
        answer += 'R';
    }
    
    if(m['F'] > m['C']) {
        answer += 'F';
    } else {
        answer += 'C';
    }
    
    if(m['M'] > m['J']) {
        answer += 'M';
    } else {
        answer += 'J';
    }
    
    if(m['N'] > m['A']) {
        answer += 'N';
    } else {
        answer += 'A';
    }
    
    return answer;
}