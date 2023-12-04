function solution(n) {
    var answer = 0;
    answer = n + 1;
    let nOneCnt = [...n.toString(2)].filter((e) => e == 1).length
    while(true) {
        let ansOneCnt = [...answer.toString(2)].filter((e) => e == 1).length

        if(nOneCnt == ansOneCnt)
            break;
        answer++;
    }
    return answer;
}