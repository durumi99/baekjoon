#include <iostream>
#include <string>
#include <vector>

#define MAX 9999999
using namespace std;

int n,m,w;
struct edge {
    int s,e,t;
};

bool bf(int n, vector <edge> edges){
    vector<int> distance(n+1,MAX);
    
    int s,e,t;
    distance[1] = 0; // 출발지점 1
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < edges.size() ; j++){ // 모든 edge 탐색
            s = edges[j].s;
            e = edges[j].e;
            t = edges[j].t;
            distance[e] = (distance[e] > distance[s] + t) ? distance[s] + t : distance[e];
        }
    }
    for (int j = 0; j < edges.size(); j++) {
		s = edges[j].s;
		e = edges[j].e;
		t = edges[j].t;
		if (distance[e] > distance[s] + t) {
			return true;
		}
	}

	return false;
}
int main() {
    int TC; cin >> TC;
    int s,e,t;
    for(int T = 0 ; T < TC ; T++){
        cin >> n >> m >> w;
        vector <edge> edges;
        
        for(int i = 0 ; i < m ;i++){ // 도로 입력
            cin >> s >> e >> t;
            edges.push_back({s,e,t});
            edges.push_back({e,s,t});
        }
        for(int i = 0 ; i < w ;i++){ // 웜홀 입력
            cin >> s >> e >> t;
            edges.push_back({s,e,-t});
        }
        if(bf(n,edges)) // 벨만포드 알고리즘
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}