#include <bits/stdc++.h>
#define MAX 100001
#define MOD 10007
using namespace std;

// 1. 위쪽 정삼각형과 함께 마름모 타일로 덮기
// 2. 왼쪽 정삼각형과 함께 마름모 타일로 덮기
// 3. 오른쪽 정삼각형과 함께 마름모 타일로 덮기
// 4. 정삼각형 타일로 덮기

int A[MAX] = {0, }; // 3번인 경우
int B[MAX] = {0, }; // 3번말고 나머지인 경우

int solution(int n, vector<int> tops) {
    int answer = 0;
    A[0] = 1;
    B[0] = (tops[0] == 1) ? 3 : 2;
    
    for (int i = 1 ; i < n ; i++) {
        A[i] = (A[i - 1] + B[i - 1]) % MOD;
        
        if (tops[i] == 1) {
            B[i] = (A[i - 1] * 2 + B[i - 1] * 3) % MOD;
        } else {
            B[i] = (A[i - 1] + B[i - 1] * 2) % MOD;
        }
    }
    
    answer = (A[n - 1] + B[n - 1]) % MOD;
    return answer;
}