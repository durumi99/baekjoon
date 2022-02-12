#include <iostream>

#define MAX 17000000
#define CITY 16

using namespace std;
int n,answer;
int w[CITY][CITY];
int dp[1 << CITY ][CITY];
void input(){
    cin >> n;
    for(int i = 0 ; i < n ; i++)    
        for(int j = 0 ; j < n ; j++)
            cin >> w[i][j];
}
int tsp(int visited, int cur){
    visited |= (1 << cur);
    //현재 도시를 visted에 추가
    if(visited == (1 << n) -1){
        if(w[cur][0] > 0)
            return w[cur][0];
        return MAX;
    }
    int & ret = dp[visited][cur];
    
    if(ret > 0)
        return ret;
    ret = MAX;
    for(int i = 0 ; i < n ; i++){
        // 방문 X 경로 O
        if(i != cur && (visited & (1 << i) ) == 0 & w[cur][i] > 0){
            int tmp = tsp(visited,i) + w[cur][i];
            if(ret > tmp)
                ret = tmp;
        }
    }
    return ret;
}
void solve(){
    answer = tsp(0,0);
    cout << answer << '\n';
}
int main() {
    input();
    solve();
    return 0;
}