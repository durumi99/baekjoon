function solution(num_list) {
    const answer = num_list.reduce((acc, el) => acc * el, 1) < Math.pow(num_list.reduce((acc, el) => acc + el, 0), 2) ? 1 : 0;
    return answer;
}