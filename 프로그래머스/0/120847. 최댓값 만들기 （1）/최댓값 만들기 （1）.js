function solution(numbers) {
    var answer = numbers.sort((a, b) => {
        return b - a;
    })[0] * numbers[1];
    return answer;
}