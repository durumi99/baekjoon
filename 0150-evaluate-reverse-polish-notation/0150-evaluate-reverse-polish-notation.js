/**
 * @param {string[]} tokens
 * @return {number}
 */
var evalRPN = function(tokens) {
    const numStack = [];

    for(const token of tokens) {
        if(!isNaN(token)) {
            numStack.push(Number(token));
            continue;
        } 

        const right = numStack.pop();
        const left = numStack.pop();

        if(token === '+') {
            numStack.push(left + right);
        } else if(token === '-') {
            numStack.push(left - right);
        } else if(token === '*') {
            numStack.push(left * right);
        } else if(token === '/') {
            numStack.push(Math.trunc(left / right));
        }
    }

    return numStack[0];
};