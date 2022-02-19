#include <iostream>

#include <cmath>

#define MAX 11
using namespace std;
int n;
int ans[2];
int map[MAX][MAX];
int l[20];
int r[20];
void input(){
    cin >> n ;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++){
            cin >> map[i][j];
    }
}

void dfs(int row, int col, int cnt, int color){
    if(col >= n){
        row++;
        if(col % 2  == 0)
            col = 1;
        else
            col = 0;
    }
    if(row >= n){
        ans[color] = max(ans[color],cnt);
        return;
    }
    
    if(map[row][col] && !l[col - row + n - 1] && !r[row + col]){
        l[col - row + n - 1] = 1;
        r[row + col] = 1;
        dfs(row,col+2,cnt+1,color);
        l[col - row + n - 1] = 0;
        r[row + col] = 0;
    }
    dfs(row,col+2,cnt,color);
}
void solve(){
    dfs(0,0,0,0);
    dfs(0,1,0,1);
    cout << ans[0] + ans[1] << '\n';
}
int main() {
    input();
    solve();
    return 0;
}