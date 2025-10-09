function solution(num_list) {
    var answer = num_list.length >= 11 ? num_list.reduce((acc, el) => acc + el, 0) : num_list.reduce((acc, el) => acc * el, 1);
    return answer;
}