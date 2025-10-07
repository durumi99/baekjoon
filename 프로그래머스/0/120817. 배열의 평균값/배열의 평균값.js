function solution(numbers) {
    var answer = numbers.reduce((acc, num) => {
        return acc + num;
    }, 0) / numbers.length;
    return answer;
}