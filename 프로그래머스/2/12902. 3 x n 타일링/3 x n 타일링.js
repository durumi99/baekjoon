const MOD = 1000000007;

function solution(n) {
    if(n % 2) {
        return 0;
    }
    var answer = 0;
    const dp = new Array(n + 1).fill(0);
    dp[0] = dp[1] = dp[3] = 1;
    dp[2] = 3;
    // dp[4] = 11;
    
    for(let i = 4 ; i <= n ; i++) {
        dp[i] += (dp[i - 2] * 3) % MOD;
        let idx = i - 4;
        while(idx >= 0) {
            dp[i] += (dp[idx] * 2) % MOD;
            idx -= 2;
        }
        dp[i] %= MOD;
    }
    
    console.log(dp);
    answer = dp[n];
    return answer;
}