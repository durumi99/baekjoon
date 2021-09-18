#include <iostream>

using namespace std;
int n,m;
const int MN = 501;
int map[MN][MN];
bool visited[MN];
bool invited[MN];
int cnt = 0;

int main() {
    cin >> n >> m;
    for(int i = 2 ; i <= m ; i++){
        int a,b; cin >> a >> b;
        map[a][b] = map[b][a] = true;
    }
    
    for(int i = 2 ; i <= n ; i++)
        if(map[1][i] == 1)
            visited[i] = invited[i] = true;
               
    for(int i = 2; i <= n ; i++){
        if(invited[i]){
            for(int j = 1 ; j <= n ; j++){
                if(map[i][j]){
                    visited[j] = true;
                }
            }
        }
    }
    
    for(int i = 2 ; i <= n ; i++)
        if(visited[i]){
            cnt++;
        }
    cout << cnt <<'\n';
    return 0;
}