function solution(arr, divisor) {
    const answer = arr.filter(el => el % divisor === 0).sort((a, b) => {
        return a - b;
    });
    
    if(answer.length === 0) {
        answer.push(-1);
    }
    
    return answer;
}