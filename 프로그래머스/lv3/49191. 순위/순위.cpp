#include <bits/stdc++.h>

#define MAX 101
using namespace std;

int arr[MAX][MAX];
int ranking[MAX];
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(int i = 1 ; i <= n ; i++)
        ranking[i] = -1;
    
    for(auto result : results) {
        arr[result[0]][result[1]] = 1;
        arr[result[1]][result[0]] = -1;
    }
    for(int i = 1 ; i <= n ; i++) {
        int loseCnt = 0;
        int winCnt = 0;
        for(int j = 1 ; j <= n ; j++) {
            if(arr[i][j] == -1)
                loseCnt++;
            if(arr[i][j] == 1)
                winCnt++;
        }
        if(loseCnt + winCnt == n-1) {
            answer++;
            ranking[i] = loseCnt+1;
        }
    }
    for(int i = 1 ; i <= n ; i++) {
        if(ranking[i] != -1) {
            for(int j = 1 ; j <= n ; j++) {
                if(arr[i][j] == 1) {
                    ranking[j] = ranking[i] + 1;
                }
                if(arr[i][j] == -1) {
                    ranking[j] = ranking[i] - 1;
                }
                
            }
        }
    }
    for(int i = 1 ; i <= n ; i++) {
        cout << ranking[i] << ' ';
    }
    return answer;
}