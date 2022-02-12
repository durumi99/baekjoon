#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>

#define MAX 101
using namespace std;

int h,w,answer;
char map[MAX][MAX];
bool key[26];
bool visit[MAX][MAX];
int dx[4] = {1 , -1 , 0 , 0};
int dy[4] = {0 , 0 , 1 , -1};
string str;
void init(){
    memset(map,0,sizeof(map));
    memset(visit,false,sizeof(visit));
    memset(key,false,sizeof(key));
    answer = 0;
    str.clear();
}
void input(){
        cin >> h >> w;
        for(int i = 1 ; i <= h ; i++){
            for(int j = 1 ; j <= w ; j++){
                cin >> map[i][j];
            }
        }
        cin >> str;
        if(str[0] != '0')
            for(int i = 0 ; i < str.size(); i ++)
                key[str[i]-'a'] = true;

}
void bfs(int a,int b){
    queue < pair<int,int> > q;
    queue < pair<int,int> > door[26];
    q.push({a,b});
    visit[a][b] = true;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0 ; i < 4 ; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            if(newX < 0 || newY < 0 || newX > h+1 || newY > w+1)
                continue;
            if(map[newX][newY] == '*' || visit[newX][newY])
                continue;
            visit[newX][newY] = true;
            
            if('A' <= map[newX][newY] && map[newX][newY] <= 'Z'){ // door
                if(key[map[newX][newY]-'A'])
                    q.push({newX,newY});
                else
                    door[map[newX][newY]-'A'].push({newX,newY});
            }
            else if('a' <= map[newX][newY] && map[newX][newY] <= 'z'){ // key
                q.push({newX,newY});
                if(!key[map[newX][newY]-'a']){
                    key[map[newX][newY]-'a'] = true;
                    
                    while(!door[map[newX][newY] - 'a'].empty()){
                        q.push(door[map[newX][newY] - 'a'].front());
                        door[map[newX][newY] - 'a'].pop();
                    }
                }
            }
            else{
                q.push({newX,newY});
                if(map[newX][newY] == '$')
                    answer++;
            }
        }
    }
}
void solve(){
    bfs(0,0);
}
int main() {
    int TC; cin >> TC;
    while(TC--){
        init();
        input();
        solve();
        cout << answer << '\n';
    }
    return 0;
}