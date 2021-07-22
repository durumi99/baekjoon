#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define arr_size 1001
#define MAX 20010
#define INF 987654321

int n,m,x,a,b,c;
//int arr[arr_size][arr_size];
int dist[MAX];
int dist2[MAX];
vector < pair <int,int> > arr[MAX];
vector < pair <int,int> > arr2[MAX];

priority_queue < pair <int,int> > pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> x;
    for(int i = 0 ; i < m ; i++){
        cin >> a >> b >> c;
        arr[a].push_back({b,c});
        arr2[b].push_back({a,c});
    }
    
    for(int i = 1 ; i <= n ; i++)
        dist[i] = dist2[i]= INF;
    
    pq.push({0,x});
    dist[x] = 0;
    
    while(pq.empty() == 0){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for(int i = 0 ; i < arr[cur].size();i++){
            int next = arr[cur][i].first;
            int ncost = arr[cur][i].second;
            if(dist[next] > cost + ncost){
                dist[next] = cost + ncost;
                pq.push({-dist[next],next});
            }
        }
    }
    
    pq.push({0,x});
    dist2[x] = 0;
    
    while(pq.empty() == 0){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for(int i = 0 ; i < arr2[cur].size();i++){
            int next = arr2[cur][i].first;
            int ncost = arr2[cur][i].second;
            if(dist2[next] > cost + ncost){
                dist2[next] = cost + ncost;
                pq.push({-dist2[next],next});
            }
        }
    }
    
    for(int i = 1 ; i <= n ; i++){
       dist[i] += dist2[i];
    }
    
    int ans = 0;
    for(int i = 1 ; i <= n ; i++){
        if(dist[i] > ans)
            ans = dist[i];
    }
    cout << ans;
    return 0;
}