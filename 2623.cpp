#include <iostream>
#include <vector>
#include <queue>
#define MAX 1111

using namespace std;
int n,m;
int degree[MAX];
vector < vector<int> > g(MAX);
void solve(){
    queue <int> q;
    queue <int> answer;
    for(int i = 1 ; i <= n ; i++){
        if(!degree[i])
            q.push(i);
    }
    
    while(!q.empty()){
        int cur = q.front();
        answer.push(cur);
        q.pop();
        for(int i = 0 ; i < g[cur].size() ; i++){
            degree[g[cur][i]]--;
            if(!degree[g[cur][i]])
                q.push(g[cur][i]);
        }
    }
    if(answer.size() == n){
        while(!answer.empty()){
            cout << answer.front() << '\n';
            answer.pop();
        }
    }
    else{
        cout << 0 << '\n';
    }
}
void input(){
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        vector <int> v;
        int tmp;
        int num; cin >> num;
        
        for(int j = 0 ; j < num ; j++){
            cin >> tmp;
            v.push_back(tmp);
        }
        for(int j = 0 ; j < v.size() - 1 ; j++){
            g[v[j]].push_back(v[j+1]);
            degree[v[j+1]]++;
        }
    }
}
int main() {
    input();
    solve();
    return 0;
}