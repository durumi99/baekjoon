/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function(nums, k) {
    k %= nums.length; // Handles both k < nums.length and k >= nums.length
    if (k === 0) return; // Early exit if no rotation needed
    const nums2 = nums.concat(nums);
    for (let i = 0; i < nums.length; i++) {
        nums[i] = nums2[(i + nums.length - k) % nums.length];
    }

};