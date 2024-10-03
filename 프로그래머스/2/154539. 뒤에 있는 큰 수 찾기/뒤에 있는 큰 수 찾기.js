function solution(numbers) {
    var answer = [];
    let curMaxN = -1;
    let stack = [];
    
    for(let i = numbers.length - 1; i >= 0 ; i--) {
        if(numbers[i] >= curMaxN) {
            curMaxN = numbers[i];
            answer.push(-1);
            stack = [];
            stack.push(numbers[i]);
            continue;
        }
        
        while(true){
          if(numbers[i] < stack[0]){
             answer.push(stack[0]);
             stack.unshift(numbers[i]); 
             break;
           }else{
               stack.shift();
           }
        } 
        
    }

    return answer.reverse();
}