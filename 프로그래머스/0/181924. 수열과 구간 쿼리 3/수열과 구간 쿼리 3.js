function solution(arr, queries) {
    var answer = [];
    queries.forEach(([a, b]) => {
        [arr[a], arr[b]] = [arr[b], arr[a]];
    })
    answer = arr;
    return answer;
}