#include <bits/stdc++.h>

using namespace std;
int n, m, K;
int A[11][11];
int ground[11][11];
vector<int> tree[11][11];
int dy[] = {-1, -1, -1, 1, 1, 1, 0, 0};
int dx[] = {-1, 0, 1, -1, 0, 1, -1, 1};

vector < pair<int, pair<int, int>> >nuts;


void springAndSummer() {
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            if(tree[i][j].empty())
                continue;
            int nuts = 0;
            vector <int> tmp;
            sort(tree[i][j].begin(), tree[i][j].end());
            
            for(int k = 0 ; k < tree[i][j].size() ; k++) {
                if(ground[i][j] >= tree[i][j][k]) {
                    ground[i][j] -= tree[i][j][k];
                    tmp.push_back(tree[i][j][k] + 1);
                } else {
                    nuts += tree[i][j][k] / 2;
                }
            }
            tree[i][j].clear();
            ground[i][j] += nuts;
            for(int k = 0 ; k < tmp.size() ; k++) {
                tree[i][j].push_back(tmp[k]);
            }
        }
    }
}


void autumn() {
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            if(tree[i][j].empty())
                continue;
            for(int k = 0 ; k < tree[i][j].size() ; k++) {
                if(tree[i][j][k] % 5 == 0) {
                    for(int a = 0 ; a < 8 ; a++) {
                        int nX = i + dx[a];
                        int nY = j + dy[a];
                        
                        if(nX <= 0 || nY <= 0 || nX > n || nY > n)
                            continue;
                            
                        tree[nX][nY].push_back(1);
                    }
                }
            }
        }
    }
}

void winter() {
    for(int j = 1 ; j <= n ; j++) {
        for(int kk = 1 ; kk <= n ; kk++) {
            ground[j][kk] += A[j][kk];
        }
    }
}

void input() {
    cin >> n >> m >> K;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            cin >> A[i][j];
            ground[i][j] = 5;
        }
    }
    
    for(int i = 0 ; i < m ; i++) {
        int x, y, age; cin >> x >> y >> age;
        tree[x][y].push_back(age);
    }
}

int main() {
    input();
    
    while(K--) {
        springAndSummer();
        autumn();
        winter();
        
    }
    int ans = 0;
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            ans += tree[i][j].size();
        }
    }
    cout << ans;
    return 0;
}