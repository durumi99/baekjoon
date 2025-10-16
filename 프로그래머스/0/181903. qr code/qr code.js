function solution(q, r, code) {
    var answer = [...code].filter((_, idx) => idx % q === r).join('');
    return answer;
}