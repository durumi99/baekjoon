function solution(n) {
    var answer = n % Math.sqrt(n) ? 2 : 1;
    return answer;
}