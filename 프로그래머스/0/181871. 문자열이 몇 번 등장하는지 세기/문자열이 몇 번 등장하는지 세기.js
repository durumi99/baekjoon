function solution(myString, pat) {
    var answer = 0;
    let idx = 0;
    while(idx < myString.length) {
        const res = myString.indexOf(pat, idx);
        if(res === -1) {
            break;
        }
        idx = res + 1;
        answer++;
    }
    return answer;
}