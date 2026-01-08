/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    const rain = new Array(height.length).fill(0);

    const [maxHeight, maxIdx] = height.reduce((acc, el, idx) => {
        if(acc[0] < el) {
            acc = [el, idx];
        }

        return acc;
    }, [0, 0]);

    let sum = 0;
    let cur = 0;
    for(let i = 0 ; i < maxIdx; i++) {
        cur = Math.max(cur, height[i]);
        sum += cur - height[i];
    }

    cur = 0;

    for(let i = height.length - 1 ; i > maxIdx; i--) {
        cur = Math.max(cur, height[i]);
        sum += cur - height[i];
    }

    return sum;
};