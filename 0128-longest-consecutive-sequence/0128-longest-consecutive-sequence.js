/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
    const set = new Set();
    nums.forEach((num)=> {
        set.add(num);
    });
    
    let answer = 0;
    for(const num of nums) {
        let cur = num;
        let sum = 0;
        while(set.has(cur)) {
            sum++;
            set.delete(cur++);
        }
        cur = num - 1;
        while(set.has(cur)) {
            sum++;
            set.delete(cur--);
        }
        answer = Math.max(answer, sum);
    };

    return answer;
};