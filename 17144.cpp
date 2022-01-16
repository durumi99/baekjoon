#include <iostream>

using namespace std;

int ap = -1;
int r,c,t;
int map[55][55];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void f(int x, int y,int dust,int tmp[][55]){
    for(int i = 0 ; i < 4 ; i++){
        int newX = x + dx[i];
        int newY = y + dy[i];
        if(map[newX][newY] == -1)
            continue;
        if(newX > r || newX < 1 || newY > c || newY < 1)
            continue;
        tmp[newX][newY] += dust / 5;
        map[x][y] -= dust / 5;
    }
}
void dustDiffusion(){
    int tmp[55][55] = {0,};
    for(int i = 1; i <= r ; i++)
        for(int j = 1 ; j <= c ; j++){
            if(map[i][j] == -1 || map[i][j] == 0)
                continue;
            f(i,j,map[i][j],tmp);    
        }
        
    for(int i = 1; i <= r ; i++){
        for(int j = 1 ; j <= c ; j++){
            map[i][j] += tmp[i][j];
        }
    }
}

void airPurifier(){
    // 1열
    for(int i = ap-1 ; i > 1 ; i--)
        map[i][1] = map[i-1][1];
    for(int i = ap+2 ; i < r ; i++)
        map[i][1] = map[i+1][1];
    
    // 1행 r행
    for(int i = 1 ; i < c ; i++){
        map[1][i] = map[1][i+1];
        map[r][i] = map[r][i+1];
    }
    
    // c열
    for(int i = 1 ; i < ap ; i++)
        map[i][c] = map[i+1][c];
    for(int i = r ; i > ap+1 ; i--)
        map[i][c] = map[i-1][c];
    
    // 공기청정기가 있는 행, 그 다음 행
    for(int i = c ; i > 2 ; i--){
        map[ap][i] = map[ap][i-1];
        map[ap+1][i] = map[ap+1][i-1];
    }
    map[ap][2] = 0;
    map[ap+1][2] = 0;
}

void countDust(){
    int cnt = 0;
    for(int i = 1; i <= r ; i++)
        for(int j = 1 ; j <= c ; j++){
            if(map[i][j] == -1)
                continue;
            cnt+= map[i][j];
        }
    cout << cnt << '\n';
}
int main() {
    cin >> r >> c >> t;
    for(int i = 1 ; i <= r ; i++)
        for(int j = 1 ; j <= c ; j++){
            cin >> map[i][j];
            if(map[i][j] == -1 && ap == -1){
                ap = i;
            }
        }
    while(t--){
        dustDiffusion();
        airPurifier();
    }  
    countDust();
    return 0;
}