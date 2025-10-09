function solution(arr) {
    var answer = arr.some((el1, idx1) => {
        return el1.some((el2, idx2) => {
            if(el2 !== arr[idx2][idx1]) {
                return true;
            }
        })
    }) ? 0 : 1;
    return answer;
}