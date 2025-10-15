function solution(n, m, section) {
    let cur = 0;
    var answer = section.reduce((acc, el) => {
        if(cur < el) {
            acc++;
            cur = el + m - 1;
        }
        
        return acc;
    }, 0);
    
    return answer;
}