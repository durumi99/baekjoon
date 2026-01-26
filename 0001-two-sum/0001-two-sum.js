/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const sortedArr = nums.map((num, idx) => ({
        num: num,
        idx: idx
    })).sort((a, b) => a.num - b.num);
    
    let left = 0;
    let right = sortedArr.length - 1;

    while(left < right){
        const sum = sortedArr[left].num + sortedArr[right].num;

        if(target === sum) {
            return [sortedArr[left].idx,  sortedArr[right].idx];
        } else if (sum > target) {
            right--;
        } else {
            left++;
        }
    }
};