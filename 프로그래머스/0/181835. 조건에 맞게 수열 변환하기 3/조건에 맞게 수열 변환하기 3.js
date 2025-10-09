function solution(arr, k) {
    var answer = [];
    if(k % 2) {
        answer = arr.map(el => el * k);
    } else {
        answer = arr.map(el => el + k);
    }
    return answer;
}