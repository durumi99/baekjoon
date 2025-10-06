function solution(n) {
    return [...String(n)].reverse().map((el) => Number(el));
}