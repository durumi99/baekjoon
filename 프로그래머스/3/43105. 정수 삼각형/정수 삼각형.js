function solution(triangle) {
    var answer = 0;
    let dp = [];
    
    triangle.forEach((cur, idx) => {
        if(idx === 0) {
            dp.push(cur);
            return;
        }
        
        const curDp = cur.reduce((acc, el, i) => {
            if (i === 0) {
                acc.push(dp[idx - 1][i] + el);
            } else if (i === cur.length - 1) {
                acc.push(dp[idx - 1][i - 1] + el);
            } else {
                acc.push(Math.max(dp[idx - 1][i - 1], dp[idx - 1][i]) + el);
            }
            return acc;
        }, []);
        
        dp.push(curDp);
    })
    
    answer = Math.max(...dp[dp.length - 1]);
    
    return answer;
}