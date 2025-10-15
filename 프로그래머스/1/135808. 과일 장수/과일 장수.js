function solution(k, m, score) {
    var answer = 0;
    score.sort((a, b) => b - a);
    let curMin = Infinity;
    answer = score.reduce((acc, el, idx) => {
        curMin = Math.min(el, curMin);
        if ((idx + 1) % m === 0) {
            acc += curMin * m;
            curMin = Infinity;
        } 
            
        return acc;
    }, 0);
    return answer;
}