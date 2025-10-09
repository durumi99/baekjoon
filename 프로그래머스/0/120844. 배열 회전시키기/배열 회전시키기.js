function solution(numbers, direction) {
    var answer = direction === 'right' ? [numbers.at(-1)].concat(numbers).slice(0, numbers.length): numbers.concat(numbers[0]).slice(1);
    return answer;
}