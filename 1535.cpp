#include <iostream>
#include <cmath>
using namespace std;

int n;
int L[22];
int J[22];
int life = 100;
int maxJ = 0;
void input(){
    cin >> n ;
    for(int i = 1 ; i <= n ; i++)
        cin >> L[i];
    for(int i = 1 ; i <= n ; i++)
        cin >> J[i];
    return;
}
void dfs(int life,int joy,int idx){
    if(idx == n+1){
        maxJ = max(maxJ,joy);
        return;
    }
    if(life-L[idx] > 0)
        dfs(life-L[idx],joy+J[idx],idx+1);
    dfs(life,joy,idx+1);
}
void solve(){
    dfs(life,0,0);
    cout << maxJ << '\n';
}
int main() {
    input();
    solve();
    return 0;
}