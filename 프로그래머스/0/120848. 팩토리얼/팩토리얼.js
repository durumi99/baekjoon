function solution(n) {
    var answer = 1;
    let tmp = 1;
    while(true) {
        answer++;
        tmp *= answer;
        if(tmp > n) {
            break;
        }
    }
    return answer - 1;
}