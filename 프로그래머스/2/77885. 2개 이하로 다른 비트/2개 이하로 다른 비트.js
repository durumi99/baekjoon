function solution(numbers) {
    var answer = [];
    
    for(const number of numbers) {
        answer.push(f(number));
    }
    return answer;
}

function f(number) {
    let stack = number.toString(2).split('').reverse();
    // console.log(stack, stack.length);
    
    let maxIdx = stack.length;    
    let idx = 0;
    
    while(idx < maxIdx + 1) {
        if(idx < maxIdx) {
            if(stack[idx] == 0) {
                stack[idx] = 1;
                if(idx != 0) {
                    stack[idx - 1] = 0;
                }
                break;
            }
        } else {
            stack.push(1);
            stack[idx - 1] = 0;
            break;
        }
        idx++;
    }
    // console.log(stack.join(''));
    // console.log(stack.length);
    
    let minNum = 0;
    for(let i = 0 ; i < stack.length ; i++) {
        minNum += Math.pow(2, i) * stack[i];
        
    }
    return minNum;
}