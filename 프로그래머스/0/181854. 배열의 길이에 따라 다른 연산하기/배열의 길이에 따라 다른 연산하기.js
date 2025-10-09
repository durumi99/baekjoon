function solution(arr, n) {
    var answer = arr.map((el, idx) => {
        return el + ((arr.length % 2 !== idx % 2) ? n : 0); 
    });
    return answer;
}