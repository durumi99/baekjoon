function solution(num_str) {
    var answer = [...num_str].reduce((acc, el) => acc + ~~el, 0);
    return answer;
}