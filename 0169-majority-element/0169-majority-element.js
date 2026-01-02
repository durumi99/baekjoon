/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    const m = new Map();

    nums.forEach((el) => {
        m.set(el, (m.get(el) || 0) + 1);
    });

    return Array.from(m).sort((a, b) => {
        return b[1] - a[1];
    })[0][0];
};