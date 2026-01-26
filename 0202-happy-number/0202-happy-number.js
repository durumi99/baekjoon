/**
 * @param {number} n
 * @return {boolean}
 */

var isHappy = function(n) {
    const set = new Set();

    const func = (n) => {
        if(n === 1) {
            return true;
        }
        const next = Array.from(String(n)).reduce((acc, el) => {
            return acc + Math.pow(Number(el), 2);
        }, 0);
        
        if(set.has(next)) {
            return false;
        }

        set.add(next);
        return func(next);
    }

    return func(n);
};