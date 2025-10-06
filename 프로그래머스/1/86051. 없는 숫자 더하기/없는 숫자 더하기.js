function solution(numbers) {
    return 45 - numbers.reduce((acc, el) => {
        return acc + el;
    }, 0);
}