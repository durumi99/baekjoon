function solution(arr, intervals) {
    var answer = intervals.reduce((acc, el) => {
        acc.push(...arr.slice(el[0], el[1] + 1));
        return acc;
    }, []);
    return answer;
}