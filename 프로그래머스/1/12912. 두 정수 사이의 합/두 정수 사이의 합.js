function solution(a, b) {
    var answer = 0;
    const start = Math.min(a, b);
    const end = Math.max(a, b);
    
    const arr = [];
    for(let i = start ; i <= end ; i++) {
        arr.push(i);
    }
    
    answer = arr.reduce((acc, el) => {
        return acc + el;
    }, 0);
    
    return answer;
}