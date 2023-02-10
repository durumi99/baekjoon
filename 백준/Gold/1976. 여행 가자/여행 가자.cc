#include <iostream>
#include <vector>

#define MAX 202
using namespace std;
int road[MAX][MAX];
int root[MAX];
int N, M;
vector <int> v;

int find(int x) {
    if(root[x] == x) {
        return x;
    }
    
    return root[x] = find(root[x]);
}

void unionF(int x, int y) {
    x = root[x];
    y = root[y];
    
    if(x == y)
        return;
    if(x > y) {
        root[x] = y;
        return;
    }
    
    root[y] = x;
}
void makeDS() {
    for(int i = 1 ; i <= N ; i++)
        root[i] = i;
        
    for(int i = 1 ; i <= N ; i++) {
        for(int j = 1 ; j <= N ; j++) {
            if(i != j && road[i][j]) {
                // cout << i << ' ' << j << '\n';
                unionF(i, j);
                // cout << root[i] << ' ' << root[j] << '\n';
            }
        }
    }
}
int main() {
    cin >> N >> M;
    for(int i = 1 ; i <= N ; i++) {
        for(int j = 1 ; j <= N ; j++) {
            cin >> road[i][j];
            // cout << road[i][j] << ' ';
        }
        // cout << '\n';
    }
    
    for(int i = 0 ; i < M ; i++) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }
    
    makeDS();
    
    int prev = v[0], cur;
    // bool canMove = true;
    for(int i = 1 ; i < v.size(); i++) {
        cur = v[i];
        // if(!canMove)
        //     continue;
        if(find(prev) != find(cur)) {
            cout << "NO";
            return 0;
        }
        prev = cur;
    }
    cout << "YES";
    return 0;
}