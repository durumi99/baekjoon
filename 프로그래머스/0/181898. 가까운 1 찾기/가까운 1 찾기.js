function solution(arr, idx) {
    var answer = -1;
    arr.some((el, idx2) =>  {
        if(el === 1 && idx2 >= idx) {
            answer = idx2;
            return true;
        } 
    });
    return answer;
}