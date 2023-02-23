#include <bits/stdc++.h>

// #define MAX 160000
#define MAX 8
#define INF 987654321

using namespace std;

set <int> dp[MAX];
void makeDp(int N, int number) {
    int num = 0;
    for(int i = 0 ; i < MAX ; i++) {
        num = num*10 + N;
        dp[i].insert(num);
    }
    
    for(int i = 1 ; i < MAX ; i++) {
        for(int j = 0 ; j < i ; j++) {
            for(auto a : dp[j]) {
                for(auto b : dp[i - j - 1]) {
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    if(b != 0)
                        dp[i].insert(a / b);
                }
            }
        }
    }
}
int solution(int N, int number) {
    int answer = -1;
    makeDp(N, number);
    
    for(int i = 0 ; i < MAX ; i++) {
        if(dp[i].count(number)) {
            answer = i + 1;
            break;
        }
    }
    return answer;
}