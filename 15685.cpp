#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#define INF 1e9

using namespace std;
int n,m,answer = INF;
vector < pair <int,int> > house;

void check_bfs(vector<vector<int>>& v) {
	vector<pair<int, int>> chicken;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] == 2)
				chicken.push_back({i,j});
		}
	}
	int cnt = 0;
    for(int i = 0 ; i < house.size() ; i++){
        int tmp = INF;
        for(int j = 0 ; j < chicken.size(); j++){
            tmp = min(tmp, abs( house[i].first - chicken[j].first ) + abs( house[i].second - chicken[j].second ) );
        }
        cnt += tmp;
    }
    
	answer = min(answer, cnt);
}
void dfs(vector<vector<int>> v, int x, int y, int cnt){
	v[x][y] = 0;

	if (cnt == m) {
		check_bfs(v);
		return;
	}

	for (int i = x; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] == 2)
				dfs(v, i, j, cnt - 1);
		}
	}
}
int main() {
    int cnt = 0;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(n));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> v[i][j];
            if(v[i][j] == 2)
                cnt++;
            else if(v[i][j] == 1)
                house.push_back({i,j});
        }
    }
    if(cnt == m )
        check_bfs(v);
    else{
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(v[i][j] == 2)
                    dfs(v,i,j,cnt - 1);
            }
        }
    }
    cout << answer;
    return 0;
}