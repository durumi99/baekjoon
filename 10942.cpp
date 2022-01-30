#include <iostream>
#include <vector>
#include <stack>
#define MAX 2222
using namespace std;
int n,m;
int num[MAX];
bool dp[MAX][MAX];
vector <pair<int,int> > v;
void makeDP(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 1 ; i + j <= n ; j++){
            int start = j;
            int end = i + j;
            
            if(start == end){ 
                dp[start][end] = true;
                continue;
            }
            
            if(start + 1 == end){
                if(num[start] == num[end])
                    dp[start][end] = true;
                else
                    continue;
            }
            if(num[start] == num[end] && dp[start+1][end-1])
                dp[start][end] = true;
        }
    }
}
void input(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
        cin >> num[i];
    cin >> m;
    for(int i = 0 ; i < m ; i++){
        int s,e;
        cin >> s >> e;
        v.push_back({s,e});
    }
}
void solve(){
    for(int i = 0 ; i < v.size() ; i++){
        if(dp[v[i].first][v[i].second])
            cout << 1 << '\n';
        else 
            cout << 0 << '\n';
    }
}
int main() {
    input();
    makeDP();
    solve();
    return 0;
}