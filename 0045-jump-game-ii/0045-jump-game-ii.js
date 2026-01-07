/**
 * @param {number[]} nums
 * @return {number}
 */
var jump = function(nums) {
    if(nums.length === 1) {
        return 0;
    }
    const dp = new Array(nums.length).fill(Infinity);
    dp[0] = 0;

    for (let i = 0; i < nums.length; i++) {
        console.log(dp[i]);

        for(let j = 1 ; j <= nums[i] ; j++) {
            dp[i + j] = Math.min(dp[i + j], dp[i] + 1);
        }

        // tmp.idx = Math.max(maxReach.idx, i + nums[i]);
        // tmp.count = Math.min(maxReach.count );
        // if (maxReach.idx >= nums.length - 1) return maxReach.count;
    }

    return dp[nums.length - 1];
};