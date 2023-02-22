#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map <string, int> m;
    for(auto ele : participant) {
        m[ele]++;
    }
    for(auto ele : completion) {
        m[ele]--;
    }
    for(auto it = m.begin() ; it != m.end(); it++) {
        if(it->second) {
            answer += it->first;
            break;
        }
    }
    return answer;
}
