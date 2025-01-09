let answer = [-1];
let maxScoreDiff = 1;

function solution(n, info) {
    dfs(n, info, 0, 0, 0, []);
    return answer;
}

function dfs(n, info, idx, aScore, rScore, result) {
    if (idx === info.length){
        if(n > 0) {
            result[idx - 1] += n;
        }
        
        if(rScore - aScore > maxScoreDiff) {
            maxScoreDiff = rScore - aScore;
            answer = result;
        }
        
        if(rScore - aScore === maxScoreDiff) {
            const reversedRes = [...result].reverse();
            const reversedAns = [...answer].reverse();
            if(reversedAns < reversedRes) {
                answer = result;
            }
        }
        return;
    }
    
    if (n > info[idx]) {
        result.push(info[idx] + 1);
        dfs(n - info[idx] - 1, info, idx + 1, aScore, rScore + 10 - idx, [...result]);
        result.pop();
    }
    
    result.push(0);
    dfs(n, info, idx + 1, aScore + (info[idx] && 10 - idx), rScore, [...result]);
    result.pop();
    
};