/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function(nums, k) {
    k %= nums.length; 
    if (k === 0) return; 
    const nums2 = nums.concat(nums);
    for (let i = 0; i < nums.length; i++) {
        nums[i] = nums2[(i + nums.length - k) % nums.length];
    }

};