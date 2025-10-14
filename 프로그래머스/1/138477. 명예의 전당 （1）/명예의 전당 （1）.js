function solution(k, score) {
    const ranking = [];
    var answer = score.map((el) => {
        ranking.push(el);
        ranking.sort((a, b) => b - a);
        
        while(ranking.length > k) {
            ranking.pop();
        }
        
        return ranking.at(-1);
    });
    
    return answer;
}