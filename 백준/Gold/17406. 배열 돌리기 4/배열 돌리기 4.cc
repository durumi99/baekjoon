#include <bits/stdc++.h>
#define INF 1e9

using namespace std;
int n, m, k;
int A[51][51];
int oper[6][3];
int visited[6];
int ans = INF;
void rotate(int A[51][51], int r, int c, int s){
    // cout << r << ' ' << c << ' ' << s << '\n';
    for(int i = 1 ; i <= s ; i++) {
        int startNum = A[r - i][c - i];
        for(int j = 0 ; j < i * 2; j++) {
            A[r - i + j][c - i] = A[r - i + j + 1][c - i];
        }
        for(int j = 0 ; j < i * 2; j++) {
           A[r + i][c - i + j] = A[r + i][c - i + j + 1];
        }
        for(int j = 0 ; j < i * 2; j++) {
            A[r + i - j][c + i] = A[r + i - j - 1][c + i];
        }
        for(int j = 0 ; j < i * 2; j++) {
            A[r - i][c + i - j] = A[r - i][c + i - j - 1];
        }
        A[r - i][c - i + 1] = startNum;
    }
}

void calcMin(int A[51][51]) {
    int minNum = INF;
    for(int i = 1 ; i <= n ; i++) {
        int sum = 0;
        for(int j = 1 ; j <= m ; j++) {
            sum += A[i][j];
        }
        minNum = min(sum, minNum);
    }
    // cout << minNum << '\n';
    ans = min(minNum, ans);
}

bool completeOper() {
    for(int i = 0 ; i < k ; i++) {
        if(!visited[i])
            return false;
    }
    
    return true;
}
void dfs(int idx, int A[51][51])  {
    int tmp[51][51];
    copy(&A[0][0],&A[0][0] + 51 * 51, &tmp[0][0]);
    rotate(tmp, oper[idx][0], oper[idx][1], oper[idx][2]);
    // cout << idx << '\n';
    // for(int i = 1 ; i <= n ; i++){
    //     for(int j = 1 ; j <= m ; j++) {
    //         cout << tmp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    if(completeOper()) {
        calcMin(tmp);
        return;
    }
    
    for(int i = 0 ; i < k ; i++) {
        if(!visited[i]) {
            visited[i] = 1;
            dfs(i, tmp);
            visited[i] = 0;
        }
    }
}
int main() {
    cin >> n >> m >> k;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= m ; j++) {
            cin >> A[i][j];
        }
    }
    for(int i = 0 ; i < k ; i++) {
        int r, c, s; cin >> r >> c >> s;
        oper[i][0] = r;
        oper[i][1] = c;
        oper[i][2] = s;
    }
    for(int i = 0 ; i < k ; i++) {
        visited[i] = 1;
        dfs(i, A);
        visited[i] = 0;
    }
    
    cout << ans;
    return 0;
}