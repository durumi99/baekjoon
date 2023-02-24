#include <bits/stdc++.h>

#define MAX 101
using namespace std;

int arr[MAX][MAX];
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(auto result : results) {
        arr[result[0]][result[1]] = 1;
    }
            
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            for(int k = 1 ; k <= n ; k++) {
                if(arr[j][i] && arr[i][k])
                    arr[j][k] = 1;
            }
        }
    }
            
    for(int i = 1 ; i <= n ; i++) {
        int cnt = 0;
        for(int j = 1 ; j <= n ; j++) {
            if(arr[i][j] || arr[j][i])
                cnt++;
        }
        if(cnt == n-1)
            answer++;
    }
    return answer;
}