function solution(s) {
    const len = Number((s.length - 1) / 2);
    var answer = s.slice(len, len + 2 - s.length % 2);
    return answer;
}