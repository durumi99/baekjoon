#include <bits/stdc++.h>

#define MAX 51
using namespace std;
// d l r u
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
char dc[] = {'d', 'l', 'r', 'u'};
int N, M, X, Y, R, C, K;
string answer = "";
string dp[MAX][MAX];

void f(int n, int m, int x, int y, int r, int c, int k) {
    N = n;
    M = m;
    X = x;
    Y = y;
    R = r;
    C = c;
    K = k;
}
bool isImpossible(int x, int y, int remainK) {
    int pathLen = abs(x - R) + abs(y - C);
    if(abs(pathLen - remainK) % 2)
        return true;
    if(pathLen > remainK)
        return true;
    return false;
}
bool cmpString(string A, string B){
    int len = min(A.length(), B.length());
    
    for(int i = 0 ; i < len ; i++) {
        if(A[i] < B[i])
            return true;
    }
    
    return false;
}
void dfs(int curX, int curY) {
    int remainK = K - dp[curX][curY].length();
    // if(remainK <= 0)
    //     return;
    // if(curX == R && curY == C) {
    //     return;
    // }
    if(isImpossible(curX, curY, remainK)) {
        return;
    }
    
    for(int i = 0 ; i < 4 ; i++) {
        int ny = curY + dy[i];
        int nx = curX + dx[i];
        if(ny <= 0 || nx <= 0 || ny > M || nx > N)
            continue;
        string tmp = dp[curX][curY] + dc[i];
        if(tmp.length() > K)
            continue;
        if(cmpString(dp[nx][ny], tmp))
            continue;
        // if(nx == R && ny == C && remainK != 1)
        //     continue;
        dp[nx][ny] = tmp;
        
        dfs(nx, ny);
    }
}
string solution(int n, int m, int x, int y, int r, int c, int k) {
    f(n, m, x, y, r, c, k);
    if(isImpossible(x, y, k))
        return "impossible";
    
    dfs(x, y);
    answer = dp[r][c];
    return answer;
}