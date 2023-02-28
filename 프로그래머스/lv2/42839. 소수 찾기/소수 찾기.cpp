#include <bits/stdc++.h>

#define MAX 10000000
using namespace std;
int pn[MAX];

void makePN() {
    for(int i = 2 ; i < MAX ; i++) {
        pn[i] = 1;
    }
    for(int i = 2 ; i < MAX ; i++) {
        if(pn[i] == 0)
            continue;
        
        for(int j = i * i ; j < MAX ; j += i) {
            pn[j] = 0;
        }
    }
}

set <int> s;
int visited[MAX];
void dfs(string cur, string numbers) {
    if(cur != "") {
        if(pn[stoi(cur)]) {
            // cout << stoi(cur) << '\n';
            s.insert(stoi(cur));
        }
    }
    
    for(int i = 0 ; i < numbers.length() ; i++) {
        if(!visited[i]) {
            visited[i] = 1;
            dfs(cur+numbers[i], numbers);
            visited[i] = 0;
        }
    }
}
int solution(string numbers) {
    int answer = 0;
    makePN();
    dfs("", numbers);
    answer = s.size();
    return answer;
}