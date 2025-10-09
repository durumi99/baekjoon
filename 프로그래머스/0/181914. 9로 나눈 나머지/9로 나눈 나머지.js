function solution(number) {
    var answer = [...number.toString()].reduce((acc, el) => (acc + el) % 9, 0);
    return answer;
}