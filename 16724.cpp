#include <iostream>
#include <set>
#define MAX 1001

using namespace std;

int parent[MAX][MAX];
int cnt = 1;
int SFcnt = 0;
int n,m;
char dir[MAX][MAX];


void input(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0 ;  i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> dir[i][j];
            parent[i][j] = -1;
        }
    }
}

int dfs(int x,int y){
    if(parent[x][y] != -1)
        return parent[x][y];
    int ret = parent[x][y];
    parent[x][y] = cnt;
    int newX = x;
    int newY = y;
    if(dir[x][y] == 'U'){ // 위
        newX--;
    }
    else if(dir[x][y] == 'D'){ // 아래
        newX++;
    }
    else if(dir[x][y] == 'L'){ // 왼쪽
        newY--;
    } 
    else if(dir[x][y] == 'R'){ // 오른쪽
        newY++;
    }
    ret = dfs(newX,newY);
    parent[x][y] = ret;
    return parent[x][y];
}
void solve(){
    
    for(int i = 0 ;  i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(parent[i][j] == -1){
                dfs(i,j);
                cnt++;
            }
        }
    }
    
    set<int> s;
    for(int i = 0 ;  i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            s.insert(parent[i][j]);
        }
    }
    
    cout << s.size() << '\n';
    return;
}
int main() {
    input();
    solve();
    return 0;
}