/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var containsNearbyDuplicate = function(nums, k) {
    const map = {};

    for(let i = 0 ; i < nums.length ; i++){
        const cur = nums[i];
        if(map[cur] !== undefined && i - map[cur] <= k) {
            return true;
        } else {
            map[cur] = i;
        }
    }

    return false;
};