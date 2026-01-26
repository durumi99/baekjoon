/**
 * @param {number[]} nums
 * @return {string[]}
 */
var summaryRanges = function(nums) {
    if(nums.length === 0) {
        return [];
    }
    let left = nums[0];
    let right;
    const answer = [];
    for(let i = 1 ; i < nums.length ; i++) {
        if(nums[i] === nums[i - 1] + 1) {
            right = nums[i];
        } else {
            if (right > left) {
                answer.push(`${left}->${right}`);
            } else {
                answer.push(`${left}`);
            }
            left = nums[i];
        } 
    }
    if (right > left) {
        answer.push(`${left}->${right}`);
    } else {
        answer.push(`${left}`);
    }
    return answer;
};