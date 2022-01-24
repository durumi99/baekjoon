#include <iostream>
#include <vector>
#include <queue>
#define MAX 33333
using namespace std;

int n,m;
vector < vector <int> > g(MAX);
int degree[MAX];

void ff(){
    queue <int> q;
    for(int i = 1 ; i <= n ; i++){
        if(!degree[i]){
            q.push(i);
        }
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        
        for(int i = 0 ; i < g[cur].size();i++){
            degree[g[cur][i]]--;
            if(!degree[g[cur][i]])
                q.push(g[cur][i]);
        }
    }
}
void input(){
    cin >> n >> m;
    int a,b;
    for(int i = 0 ; i < m ; i++){
        cin >> a >> b;
        g[a].push_back(b);
        degree[b]++;
    }
}
int main() {
    input();
    ff();
    return 0;
}