#include <bits/stdc++.h>

#define MAX 51
#define INF 987654321

using namespace std;

int N;
int miro[MAX][MAX];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    for(int i = 0 ; i < N ; i++) {
    	string tmp; cin >> tmp;
        for(int j = 0 ; j < N ; j++) {
        	miro[i][j] = tmp[j] - '0';
        }
    }
    
    int visited[N][N];
    for(int i = 0 ; i < N ; i++)
    	for(int j = 0 ; j < N ; j++)
    		visited[i][j] = INF;
    visited[0][0] = 0;
    
    queue <pair<int, int>> q;
    q.push({0, 0});

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        
        for(int i = 0 ; i < 4 ; i++) {
        	int nY = y + dy[i];
        	int nX = x + dx[i];
        	
        	if(nY < 0 || nY >= N || nX < 0 || nX >= N)
        		continue;
        	int nCost = visited[y][x] + !miro[y][x];
        	if(visited[nY][nX] <= nCost)
        		continue;
        	visited[nY][nX] = nCost;
        	q.push({nY, nX});
        }
    }
    cout << visited[N-1][N-1];
    return 0;
}