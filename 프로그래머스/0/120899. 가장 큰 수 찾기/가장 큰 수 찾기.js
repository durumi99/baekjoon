function solution(array) {
    var answer = [];
    answer.push(Math.max(...array));
    answer.push(array.indexOf(answer[0]))
    return answer;
}