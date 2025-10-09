function solution(num, k) {
    var answer = [...num.toString()].indexOf(k.toString());
    if(answer !== -1) 
        answer++;
    return answer;
}