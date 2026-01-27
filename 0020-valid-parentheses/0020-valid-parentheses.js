/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    const stack = [];
    const opener = ['(', '{', '['];
    const closer = [')', '}', ']'];

    for(let i = 0 ; i < s.length ; i++) {
        const cur = s[i];
        if(stack.length === 0 || opener.includes(cur)) {
            stack.push(cur);
        } else {
            const top = stack.at(-1);
            if(top === '('){
                if(cur === ')') {
                    stack.pop();
                } else {
                    return false;
                } 
            } else if(top === '{') {
                if(cur === '}') {
                    stack.pop();
                } else {
                    return false;
                } 
            } else if(top === '[') {
                if(cur === ']') {
                    stack.pop();
                } else  {
                    return false;
                } 
            } 
        }
    }

    return stack.length === 0;
};