function solution(numLog) {
    var answer = numLog.slice(1).map((el, idx) => {
        const prev = numLog[idx];
        
        if(prev + 1 === el) {
            return 'w';
        } else if (prev - 1 === el) {
            return 's';
        } else if (prev + 10 === el) {
            return 'd';
        } else {
            return 'a';
        }
    }).join('');
    
    return answer;
}