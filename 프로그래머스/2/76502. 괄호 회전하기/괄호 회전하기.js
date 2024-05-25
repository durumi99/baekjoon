function solution(s) {
    var answer = 0;
    const ss = s.concat(s);
    const len = s.length;
    console.log(ss);
    
    for(let i = 0 ; i < len ; i++) {
        let stack = [];
        let chk = true;
        
        for(let j = 0 ; j < len ; j++) {
            if(stack.len == 0) {
                stack.push(ss[i + j]);
                continue;
            }
            
            if(ss[i + j] == '{' || ss[i + j] == '(' || ss[i + j] == '[') {
                stack.push(ss[i + j]);
                continue;
            }
            
            const lastCh = stack.pop();
            if(lastCh == '{' && ss[i + j] == '}') {
                continue;
            }
            if(lastCh == '(' && ss[i + j] == ')') {
                continue;
            }
            if(lastCh == '[' && ss[i + j] == ']') {
                continue;
            }
            chk = false;
            break;
        }
        
        if(chk && stack.length == 0) {
            answer++;
        }
    }
    return answer;
}