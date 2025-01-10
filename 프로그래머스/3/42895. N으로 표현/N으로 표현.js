function solution(N, number) {
    if(N === number) {
        return 1;
    }
    let dp = [];
    dp.push(0);
    let num = N;
    for(let i = 0 ; i < 8 ; i++) {
        let s = new Set();
        s.add(num);
        dp.push(s);
        num = num * 10 + N;
    }
    
    for(let i = 2 ; i <= 8 ; i++) {
        for(let j = 1 ; j < i ; j++) {
            dp[i - j].forEach((el1) => {
                dp[j].forEach((el2) => {
                    dp[i].add(el1 + el2);
                    dp[i].add(el1 - el2);
                    dp[i].add(el1 * el2);
                    if(el2 !== 0)
                        dp[i].add(Math.floor(el1 / el2));
                });
            });
        }
        
        if(dp[i].has(number)) {
            return i;
        }
    }
    
    return -1;
}