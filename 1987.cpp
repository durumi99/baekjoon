#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int r,c;
int answer = 0;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
char map[22][22];
vector <int> v;
int visited[30];
// int cnt(int visited[30]){
//     int tmp = 0;
//     for(int i = 0 ; i < 30 ; i++){
//         //cout << (char)('A'+i) << ' ';
//         if(visited[i] == 1){
//             //cout << (char)('A'+i) << ' ';
//             tmp++;
//         }
//     }
//     //cout << '\n';
//     return tmp;
// }
void f(int x,int y,int cnt){
    answer = max(answer,cnt);
    
    for(int i = 0 ; i < 4 ; i++){
        int newX = x + dx[i];
        int newY = y + dy[i];
        if(newX < 1 || newY < 1 || newX > r || newY > c || visited[map[newX][newY]-'A'])
            continue;
        visited[map[newX][newY]-'A'] = 1;
        f(newX,newY,cnt+1);
        visited[map[newX][newY]-'A'] = 0;
    }
}
void input(){
    cin >> r >> c;
    for(int i = 1 ; i <= r ; i++){
        string tmp; cin >> tmp;
        for(int j = 1 ; j <= c ; j++){
            map[i][j] = tmp[j-1];
        }
    }
}
int main() {
    input();
    visited[map[1][1]-'A'] = 1;
    f(1,1,1);
    cout << answer << '\n';
    return 0;
}