/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
    if (nums.length === 0) return 0;

    const set = new Set(nums);
    let longest = 1;

    for (const x of set) {
        if (!set.has(x - 1)) {
            let curr = x;
            let length = 1;

            while (set.has(curr + 1)) {
                curr++;
                length++;
            }
            longest = Math.max(longest, length);
        }
    }
    return longest;
};