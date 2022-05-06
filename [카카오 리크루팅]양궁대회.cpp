#include <string>
#include <vector>

using namespace std;

#include <iostream>

vector <int> win(11);
int pointDif = 0;

bool isBetter(vector<int> ryan){
    
}
void compare(vector <int> appeach,vector <int> ryan){
    int a = 0;
    int r = 0;
    
    for(int i = 0 ; i < 11; i++){
        if(appeach[i] == 0 && ryan[i] == 0)
            continue;
        if(appeach[i] >= ryan[i])
            a += 10-i;
        else
            r += 10-i;
    }
    if(a >= r)
        return;
    
    if( (r-a) > pointDif){
        win.clear();
        win = ryan;
        pointDif = r-a;
    }
    else if( (r-a) == pointDif){ // 점수 차이가 동일
        bool flag = false;
        for(int i = 10 ; i >= 0 ; i--){
            if(ryan[i] > win[i]){
                flag = true;
                break;
            }
            if(win[i] > ryan[i])
                break;
        }
        if(flag){
            win.clear();
            win = ryan;
        }
    }    
    return;
}

void dfs(int n,int cur,vector<int> info,vector <int> tmp){
    if(n == 0){
        compare(info,tmp);
        return;
    }
    if(cur == 10){
        tmp[cur] = n;
        compare(info,tmp);
        return;
    }
    int next = info[cur] + 1;
    if(n >= next){
        tmp[cur] = next;
        dfs(n-next,cur+1,info,tmp);
        tmp[cur] = 0;
    }
    dfs(n,cur+1,info,tmp);
}
vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    win.clear();
    vector <int> tmp(11);
    dfs(n,0,info,tmp);
    cout << pointDif << '\n';
    if(win.empty())
        answer.push_back(-1);
    else
        answer = win;
    return answer;
}