#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int aIdx = 0, bIdx = 0;
    while(aIdx < A.size() && bIdx < B.size()) {
        if(B[bIdx] > A[aIdx]) {
            answer++;
            bIdx++;
            aIdx++;
        } else {
            bIdx++;
        }
    }
    
    return answer;
}