function solution(n, k) {
    const answer = Array.from({ length: Math.floor(n / k) }, (_, i) => (i + 1) * k);
    return answer;
}