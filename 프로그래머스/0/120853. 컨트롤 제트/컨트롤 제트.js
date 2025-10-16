function solution(s) {
    let last = -1;
    
    var answer = s.split(' ').reduce((acc, el) => {
        if(el === 'Z') {
            return acc - last;
        }
        
        last = ~~el;
        return acc + last;
    }, 0);
    
    return answer;
}