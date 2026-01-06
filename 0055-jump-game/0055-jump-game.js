/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function(nums) {
    const last = nums.length - 1;
    const visited = new Set();

    const dfs = (cur) => {
        if(cur === last) {
            return true;
        }

        const jumpLength = nums[cur];
        let result = false;

        for(let i = cur + jumpLength ; i >= cur ; i--) {
            if(!visited.has(i)) {
                visited.add(i);
                result |= dfs(i);
                if(result) {
                    return true;
                }
            }
        }

        return result;
    }

    return dfs(0);
};