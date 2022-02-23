#include <iostream>
#include <cstring>
#include <cmath>
#define MAX 501
#define INF 1e9
using namespace std;
int K;
int td[MAX];
int dp[MAX][MAX];
int sum[MAX];
void init(){
    memset(dp,0,sizeof(dp));
    memset(td,0,sizeof(td));
    memset(sum,0,sizeof(sum));
}
void solve(){
    for (int i = 1; i <= K; i++)
		{
			for (int j = 1; j <= K - i; j++)
			{
				dp[j][i + j] = INF;
				for (int k = j; k < i + j; k++)
				{
					dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + sum[i + j] - sum[j - 1]);
				}
			}
		}
}
int main() {
    int TC; cin >> TC;
    while(TC--){
        //init();
        cin >> K;
        for(int i = 1 ; i <= K ; i++){
            cin >> td[i];
            sum[i] = sum[i-1] + td[i];
        }
        solve();
        cout << dp[1][K] << '\n';
    }
    return 0;
}