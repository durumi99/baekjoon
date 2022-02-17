#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 101
using namespace std;

struct Shark{
    int r; // x좌표
    int c; // y좌표
    int speed; // 속력
    int dir; // 이동방향
    int size; // 크기
    int num;
};

int r,c,m,ans;
vector <int> map[MAX][MAX];
vector <Shark> S;

int dx[] = { 0, -1, 1, 0, 0 };
int dy[] = { 0, 0, 0, 1, -1 };

bool cmp(int a, int b){
    if (S[a].size > S[b].size) 
        return true;
    return false;
}

void input(){
    cin >> r >> c >> m;
    for(int i = 0 ; i < m ; i++){
        int r,c,s,d,z;
        cin >> r >> c >> s >> d >> z;
        S.push_back({r,c,s,d,z,i});
        map[r][c].push_back(i);
    }
}

bool check(){
    for(int i = 0 ; S.size() ; i++)
        if(S[i].size != 0)
            return false;
    return true;
}

void fishing(int idx){
    for(int i = 0 ; i <= r ; i++){
        if(map[i][idx].size() != 0){
            ans += S[map[i][idx][0]].size;
            S[map[i][idx][0]].size = 0;
            map[i][idx].clear();
            break;
        }
    }
}

void moveShark(){
    for(int i = 0 ; i < S.size() ; i++){
        if(S[i].size == 0)
            continue;
        int x = S[i].r;
        int y = S[i].c;
        map[x][y].clear();
    }
    
    for(int i = 0 ; i < S.size() ; i++){
        if(S[i].size == 0)
            continue;
        int x = S[i].r;
        int y = S[i].c;
        int dir = S[i].dir;
        int speed = S[i].speed;
        
        if(dir == 1 || dir == 2){
            int rotate = (r-1) * 2;
            if(speed >= rotate)
                speed %= rotate;
            
            for(int j = 0 ; j < speed ; j++){
                int nx = x + dx[dir];
                if(nx < 1){
                    nx += 2;
                    dir = 2;
                }
                if(nx > r){
                    nx -= 2;
                    dir = 1;
                }
                x = nx;
            }
        }
        else{
            int rotate = (c-1) * 2;
            if(speed >= rotate)
                speed %= rotate;
            
            for(int j = 0 ; j < speed ; j++){
                int ny = y + dy[dir];
                if(ny < 1){
                    ny += 2;
                    dir = 3;
                }
                if(ny > c){
                    ny -= 2;
                    dir = 4;
                }
                y = ny;
            }
        }
        S[i].r = x;
        S[i].c = y;
        S[i].dir = dir;
        map[x][y].push_back(i);
    }
}

void eatShark(){
    for(int i = 1 ; i <= r ; i++){
        for(int j = 1 ; j <= c ; j++){
            if(map[i][j].size() > 1){
                sort(map[i][j].begin(),map[i][j].end(), cmp);
                int liveIdx = map[i][j][0];
                for(int k = 1 ; k < map[i][j].size() ; k++){
                    int curIdx = map[i][j][k];
                    S[curIdx].size = 0;
                    S[curIdx].r = -1;
                    S[curIdx].c = -1;
                }
                map[i][j].clear();
                map[i][j].push_back(S[liveIdx].num);
            }
        }
    }
}

void solve(){
    if(m == 0){
        cout << 0 << '\n';
        return;
    }
    for(int i = 1 ; i <= c ; i++){
        if(check())
            break;
        fishing(i);
        moveShark();
        eatShark();
    }
    cout << ans << '\n';
}
int main() {
    input();
    solve();
    return 0;
}