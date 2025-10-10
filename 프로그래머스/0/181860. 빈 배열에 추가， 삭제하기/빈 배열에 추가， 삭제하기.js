function solution(arr, flag) {
    var answer = [];
    flag.forEach((el, idx) => {
        if(el) {
            for(let i = 0 ; i < arr[idx] * 2 ; i++) {
                answer.push(arr[idx]);
            }
        } else {
            for(let i = 0 ; i < arr[idx] ; i++) {
                answer.pop(arr[idx]);
            }
        }
    });
    return answer;
}