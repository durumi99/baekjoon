function solution(my_string, indices) {
    var answer = '';
    answer = [...my_string].filter((_,idx) => !new Set(indices).has(idx)).join('');
    return answer;
}