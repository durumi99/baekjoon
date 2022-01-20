#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;
int m;
vector <long long int> n;
vector <int> s;
long long int f(long long int diceN,int b){
    if(b == 1) return diceN % MOD;
    if(b & 1)
        return f(diceN,b-1)* diceN % MOD;
    return f(diceN*diceN%MOD , b/2);
}
void result(){
    long long int answer = 0;
    for(int i = 0 ; i < m ; i++){
        answer += s[i] * f(n[i], MOD -2) % MOD;
        answer %= MOD;
    }
    cout << answer << '\n';
}
void input(){
    int tmpN,tmpS;
    cin >> m;
    for(int i = 0 ; i < m ; i++){
        cin >> tmpN >> tmpS;
        n.push_back(tmpN);
        s.push_back(tmpS);
    }
}
int main() {
    input();
    result();
    return 0;
}