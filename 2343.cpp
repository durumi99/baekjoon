#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;
int minPower = 0;
//int dp[5]; // 0 은 왼발 1은 오른발
vector < pair<int, pair<int,int> > > dp(100001); // cost, left, right 
vector <int> v;

void input(){
    while(true){
        int tmp; cin >> tmp;
        if(!tmp)
            break;
        v.push_back(tmp);
    }
}
int move(int from, int to){
    if(from==to) return 1;
    switch(from){
    case 0: return 2;
    case 1: return to==3 ? 4 : 3;
    case 2: return to==4 ? 4 : 3;
    case 3: return to==1 ? 4 : 3;
    case 4: return to==2 ? 4 : 3;
    }
}
void solve(){
    dp[0] = {2,{v[0],-1}};
    for(int i = 1 ;  i < v.size() ; i++ ){
        int cost = dp[i-1].first;
        int left = dp[i-1].second.first;
        int right = dp[i-1].second.second;
        //cout << cost << ' ' << left << ' ' << right << '\n'; 
        if(v[i] == left || v[i] ==right){ // 왼발이나 오른 발과 같은 칸 + 1
            dp[i] = {cost+1,{left,right}};
        }
        else if(left == -1){ // 왼발이 원점 + 2 
            dp[i] = {cost+2,{v[i],right}};
        }
        else if(right == -1){ // 오른발이 원점 + 2
            dp[i] = {cost+2,{left,v[i]}};
        }
        else if(abs(v[i] - left) == 1 || abs(v[i] - left) == 3){ // 왼발 인접
            dp[i] = {cost+3,{v[i],right}};
        }
        else if(abs(v[i] - right) == 1 || abs(v[i] - right) == 3){ // 오른발 인접
            dp[i] = {cost+3,{left,v[i]}};
        }
        else
            dp[i] = {cost+4,{left,v[i]}};
    }
    for(int i = 0 ; i < 4 ; i++)
         cout << dp[i].first << '\n';
    //cout << dp[v.size()-1].first << '\n';
}
int main() {
    input();
    solve();
    return 0;
}