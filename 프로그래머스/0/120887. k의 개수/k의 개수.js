function solution(i, j, k) {
    var answer = Array.from({length : j - i + 1}, (_, idx) => idx + i).reduce((acc, el) => {
        return acc + [...el.toString()].reduce((acc, el) => {
            return acc + (el === k.toString() ? 1 : 0);
        }, 0);
    }, 0);
    return answer;
}