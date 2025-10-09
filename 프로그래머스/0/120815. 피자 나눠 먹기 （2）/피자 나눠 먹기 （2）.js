function solution(n) {
    var answer = n / gcd(n, 6);
    return answer;
}

function gcd(a, b) {
    if(a % b === 0) {
        return b;
    }
    
    return gcd(b, a % b);
}