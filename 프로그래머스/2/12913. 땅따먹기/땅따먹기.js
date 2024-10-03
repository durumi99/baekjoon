function solution(land) {
    var answer = 0;
    let dp = new Array(land.length).fill(new Array(4).fill(0));
    dp[0] = [...land[0]];
    
    for(let i = 1 ; i < land.length ; i++) {
        let cur = [];
        for(let j = 0 ; j < 4 ; j++) {
            let tmp = [...dp[i - 1]];
            tmp.splice(j, 1);
            cur.push(Math.max(...tmp) + land[i][j]); 
        }
        dp[i] = [...cur];
    }
    
    // console.log(dp);
    return Math.max(...dp[land.length - 1]);
}