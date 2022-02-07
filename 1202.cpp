#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 333333

using namespace std;

int n,k;
vector < pair<int,int> > jew;
vector <int> c;
priority_queue <int> pq;

void input(){
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++){
        long long mass,value;
        cin >> mass >> value;
        jew.push_back({mass,value});
    }
    sort(jew.begin(),jew.end());
    
    for(int i = 0 ; i < k ; i++){
        int tmp;
        cin >> tmp;
        c.push_back(tmp);
    }
    sort(c.begin(),c.end());
}
void solve(){
    long long answer = 0;
    int idx = 0;
    for(int i = 0 ; i < k ; i++){
        while(idx < n && jew[idx].first <= c[i])
            pq.push(jew[idx++].second);
        if(!pq.empty()){
            answer += (long long)pq.top();
            pq.pop();
        }
    }
    cout << answer << '\n';
}
int main() {
    input();
    solve();
    return 0;
}