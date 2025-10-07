function solution(s1, s2) {
    var answer = s1.reduce((acc, el) => {
        if(new Set(s2).has(el)) {
            acc++;
        }
        
        return acc;
    }, 0);
    return answer;
}