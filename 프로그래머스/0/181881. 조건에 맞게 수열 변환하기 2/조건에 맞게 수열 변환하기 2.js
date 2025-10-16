function solution(arr) {
    var answer = 0;
    let prev = [...arr];
    while(true) {
        arr = f(arr);
        if(isEqual(prev, arr)) {
            break;
        }
        
        answer++;
        prev = [...arr];
    }
    return answer;
}
    
function f(arr) { 
    return arr.map(el => {
        if (el >= 50 && el % 2 === 0) {
            return el / 2;
        } 
        if (el < 50 && el % 2) {
            return el * 2 + 1;
        }
        
        return el;
    })
}

function isEqual(a, b) {
    if(a.length !== b.length) {
        return false;
    }
    
    return a.every((el, idx) => {
        return el === b[idx];
    })
}