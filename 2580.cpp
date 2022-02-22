#include <iostream>

using namespace std;

int arr[9][9];
bool row[9][9];
bool col[9][9];
bool square[9][9];
void output(){
    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ; j < 9 ; j++)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }
}
void bt(int cnt){
    int x = cnt / 9;
    int y = cnt % 9;
    
    if(cnt == 81){ // 스도쿠가 완성되면 출력
        output();
        exit(0);
    }
    if(arr[x][y] == 0){
        for(int i = 1 ; i <= 9 ; i++){
            if(!row[x][i] && !col[y][i] && !square[ (x / 3) * 3 + (y / 3) ][i]){
                row[x][i] = true;
                col[y][i] = true;
                square[ (x / 3) * 3 + (y / 3) ][i] = true;
                arr[x][y] = i;
                bt(cnt+1);
                arr[x][y] = 0;
                row[x][i] = false;
                col[y][i] = false;
                square[ (x / 3) * 3 + (y / 3) ][i] = false;
                
            }
        }
    }
    else
        bt(cnt+1);
}
void input(){
    for(int i = 0 ; i < 9 ; i++)
        for(int j = 0 ; j < 9 ; j++){
            scanf("%1d",&arr[i][j]);
            if(arr[i][j]){
                row[i][arr[i][j]] = true;
                col[j][arr[i][j]] = true;
                square[( i / 3) * 3 + ( j / 3 ) ][arr[i][j]] = true;
            }
        }
}
int main() {
    input();
    bt(0);
    return 0;
}