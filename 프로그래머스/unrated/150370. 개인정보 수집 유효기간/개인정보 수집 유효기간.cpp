#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

map <char, int> m; 
int getDate(int year, int month, int day) {
    int tmp = 0;
    
    tmp += 28 * 12 * (year - 1);
    tmp += 28 * (month - 1);
    tmp += day;
    
    return tmp;
}
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    for(int i = 0 ; i < terms.size() ; i++) {
        m.insert({terms[i][0], stoi(terms[i].substr(2))});
    }
    int todayDate = getDate(stoi(today.substr(0, 4)), stoi(today.substr(5, 2)), stoi(today.substr(8, 2)));
    
    for(int i = 0 ; i < privacies.size() ; i++) {
        char type = privacies[i][11];
        int year = stoi(privacies[i].substr(0, 4));
        int month = stoi(privacies[i].substr(5, 2)) + m[type];
        int day = stoi(privacies[i].substr(8, 2));
                                    
        int tmp = getDate(year, month, day);
        
        if(tmp <= todayDate) {
            answer.push_back(i+1);
        }
    }
    
    return answer;
}
