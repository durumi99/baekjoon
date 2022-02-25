#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

#define RED 1
#define BLUE 2
#define MAX 20001
using namespace std;

int v,e;
vector <int > g[MAX];
int visit[MAX];
void bfs(int start){
    queue <int> q;
    int color = RED;
    
    visit[start] = color;
    q.push(start);
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        if(visit[now] == RED)
            color = BLUE;
        else if(visit[now] == BLUE)
            color = RED;
            
        for(int i = 0 ; i < g[now].size() ; i++){
            int next = g[now][i];
            if(!visit[next]){
                visit[next] = color;
                q.push(next);
            }
        }
    }
}
bool isBG(){
    for(int i = 1 ; i <= v ; i++){
        for(int j = 0 ; j < g[i].size(); j++){
            int next = g[i][j];
            if(visit[i] == visit[next])
                return false;
        }
    }
    return true;
}
int main() {
    int K; cin >> K;
    while(K--){
        cin >> v >> e;
        int a,b;
        for(int i = 0 ; i < e ; i++){
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        for (int i = 1; i <= v; i++) { 
            if (!visit[i]) { // 해당 노드를 아직 방문하지 않았다면,
                bfs(i);
            } 
        }
        if(isBG())
            cout << "YES\n";
        else
            cout << "NO\n";
        for(int i = 0 ; i <= v; i++)
            g[i].clear();
        memset(visit,false,sizeof(visit));
    }
    return 0;
}