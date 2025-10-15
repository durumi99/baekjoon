function solution(array) {
    var answer = array.join('').split('').reduce((acc, el) => acc + (el === '7' ? 1 : 0), 0);
    return answer;
}