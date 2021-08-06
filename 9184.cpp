#include <iostream>
#define MAX_N 110
using namespace std;
int a,b,c;
long long dp[MAX_N][MAX_N][MAX_N];
void setDP(){
    dp[70][70][70] = 1048576;
    for(int i = 0 ; i <= 100 ; i++)
        for(int j = 0 ; j <= 100 ; j++)
            for(int k = 0 ; k <= 100 ; k++){
                if(i <= 50 || j <= 50 || k <= 50)
                    dp[i][j][k] = 1;
                else if(i > 70 || j > 70 || k > 70)
                    dp[i][j][k] = dp[70][70][70];  
                else if(i < j && j < k)
                    dp[i][j][k] = dp[i][j][k-1] + dp[i][j-1][k-1] -dp[i][j-1][k];
                else
                    dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k] + dp[i-1][j][k-1] - dp[i-1][j-1][k-1];
            }   
}
int main() {
    int tmpA,tmpB,tmpC;
    setDP();
    while(cin >> tmpA >> tmpB >> tmpC){
        if( tmpA == -1 && tmpB == -1 && tmpC == -1)
            break;
        cout << "w(" << tmpA << ", " << tmpB << ", " << tmpC << ") = " << dp[tmpA+50][tmpB+50][tmpC+50] << '\n';
    }
    return 0;
}