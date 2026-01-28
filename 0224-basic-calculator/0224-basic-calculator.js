/**
 * @param {string} s
 * @return {number}
 */
var calculate = function(s) {
    let res = 0;
	let sign = 1;
	let num = 0;
	const stack = [];

    for (const c of s) {
        if(c === ' ') {
            continue;
        }

        if(c >= "0" && c <= "9"){
            num = num * 10 + Number(c);
        } else if(c === '+') {
            res += sign * num;
            sign = 1;
            num = 0;
        } else if(c === '-') {
            res += sign * num;
            sign = -1;
            num = 0;
        } else if(c === '(') {
            stack.push(res);
            stack.push(sign);
            res = 0;
            sign = 1;
        } else {
            res += sign * num;
            num = 0;
            res *= stack.pop();
            res += stack.pop();
        }
    }

    res += sign * num;
    return res;
};