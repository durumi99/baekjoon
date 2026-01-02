/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function (nums) {
    let j = 0;
    const s = new Set();
    for (let i = 0; i < nums.length; i++) {
        if (!s.has(nums[i])) {
            s.add(nums[i]);
            nums[j++] = nums[i];
        }
    }

    return j;
};