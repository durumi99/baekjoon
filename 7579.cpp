#include <iostream>

using namespace std;
const int MN = 111;
const int MK = 10101010;
int N,M;
int mem[MN];
int cost[MN];
int dp[MK];
int memsum,costsum;
int main() {
    cin >> N >> M;
    for(int i = 1 ; i <= N ; i++){
        cin >> mem[i];
        memsum += mem[i];
    }
    for(int i = 1 ; i <= N ; i++){
        cin >> cost[i];
        costsum += cost[i];
    }
    
    for(int i = 1 ; i <= N ; i++)
        for(int j = memsum - M ; j >= 0 ; j--)
            if(j >= mem[i])
                dp[j] = max(dp[j], dp[j-mem[i]] + cost[i]);
         
    cout << costsum - dp[memsum - M];
    return 0;
}