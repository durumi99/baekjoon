/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function (nums) {
    let j = 0;
    const m = new Map();
    for (let i = 0; i < nums.length; i++) {
        if (~~m.get(nums[i]) < 2) {
            m.set(nums[i], (m.get(nums[i]) || 0) + 1);
            nums[j++] = nums[i];
        }
    }
    
    return j;
};