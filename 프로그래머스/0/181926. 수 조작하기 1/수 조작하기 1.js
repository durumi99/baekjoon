function solution(n, control) {
    var answer = [...control].reduce((acc, el) => {
        if(el === 'w') {
            acc++;
        } else if(el === 's') {
            acc--;
        } else if(el === 'd') {
            acc += 10;
        } else {
            acc -= 10;
        }
        
        return acc;
    }, n);
    return answer;
}