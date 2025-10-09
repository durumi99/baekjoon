function solution(d, budget) {
    var answer = 0;
    d.sort((a, b) => a - b);
    
    d.forEach((el) => {
        if(budget >= el) {
            budget -= el;
            answer++;
        }
    });
    
    return answer;
}