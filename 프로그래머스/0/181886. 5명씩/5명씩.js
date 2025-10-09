function solution(names) {
    var answer = names.filter((el, idx) => idx % 5 === 0);
    return answer;
}