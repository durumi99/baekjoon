#include <iostream>
#include <map>
using namespace std;
int n,s;
int num[44];
map <int,int> subsum;
long long answer = 0;
void input(){
    cin >> n >> s;
    for(int i = 0 ; i < n ; i++)
        cin >> num[i];
}
void rightSeq(int st,int sum){
    if(st == n){
        subsum[sum]++;
        return;
    }
    rightSeq(st+1,sum+num[st]);
    rightSeq(st+1,sum);
}
void leftSeq(int st,int sum){
    if(st == n/2){
        answer += subsum[s-sum];
        return;
    }
    leftSeq(st+1,sum+num[st]);
    leftSeq(st+1,sum);
}
void solve(){
    rightSeq(n/2,0);
    leftSeq(0,0);
    if(!s)
        answer--;
    cout << answer << '\n';
}
int main() {
    input();
    solve();
    return 0;
}