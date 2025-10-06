function solution(num) {
    var answer = 0;
    
    while(num !== 1 && answer < 500) {
        num = collatz(num);
        answer++;
    }
    
    
    return answer === 500 ? -1 : answer;
}

function collatz(n) {
    if(n % 2 == 0) {
        return n / 2;
    } else {
        return n * 3 + 1;
    }
}