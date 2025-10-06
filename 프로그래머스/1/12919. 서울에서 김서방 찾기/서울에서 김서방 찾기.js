function solution(seoul) {
    let x;
    seoul.some((el, idx) => {
        if(el === 'Kim') {
            x = idx;
            return;
        }
    })
    
    var answer = `김서방은 ${x}에 있다`;
    return answer;
}