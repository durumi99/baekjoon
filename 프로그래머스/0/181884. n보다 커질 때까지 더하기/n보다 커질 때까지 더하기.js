function solution(numbers, n) {
    var answer = 0;
    
    let idx = 0;
    
    while(numbers.length > idx && answer <= n) {
        answer += numbers[idx];
        idx++;
    }
    return answer;
}