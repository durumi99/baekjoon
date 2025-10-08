function solution(n, m) {
    const max = Math.max(n, m);
    const min = Math.min(n, m);
    var answer = [gcd(min, max), lcm(min, max)];
    return answer;
}

function gcd(n, m) {
    if(m % n === 0) {
        return n;
    }
    
    return gcd(m % n, n);
}

function lcm(n, m) {
    return n * m / gcd(n, m);
}