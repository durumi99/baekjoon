function solution(left, right) {
    var answer = 0;
    
    for (let i = left ; i <= right ; i++) {
        const acc = Array(i + 1).fill(0).reduce((acc, _, idx) => {
            if(i % (idx + 1) === 0) {
                acc ++;
            }
            
            return acc;
        }, 0);
        
        answer += acc % 2 ? -i : i;
    }
    
    return answer;
}