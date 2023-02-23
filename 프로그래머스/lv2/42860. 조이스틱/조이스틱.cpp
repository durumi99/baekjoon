#include <bits/stdc++.h>

using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.length();
    int turn = len-1;
    
    for(int i = 0 ; i < len ; i++) {
        if(name[i] - 'A' < 14)
            answer += name[i] - 'A';
        else
            answer += 'Z' - name[i] + 1;
        
        int idx = i + 1;
        while(idx < len && name[idx] == 'A')
            idx++;
        
        turn = min(turn, i + len - idx + min(i, len - idx));
    }
    
    answer += turn;
    return answer;
}