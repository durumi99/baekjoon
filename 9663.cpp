#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

int n,ans;
int visited[15]; // visted[i] = j : [i][j] 에 퀸 위치
vector < pair<int,int> > v;


void backtracking(int cnt){
    bool ko;
    if(cnt == n){
        ans++;
        return;
    }
    for(int i = 0; i < n ; i++){
        ko = true;
        for(int j = 0 ; j < cnt ; j++){
            if(visited[j] == i || abs(cnt-j) == abs(i-visited[j])){
                ko = false;
                break;
            }
        }
        if(ko){
            visited[cnt] = i;
            backtracking(cnt+1);
        }
    }
    return;
}
int main() {
    cin >> n;
    backtracking(0);
    cout << ans;
    return 0;
}