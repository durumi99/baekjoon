/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(numbers, target) {
    let curSum;
    let index = [0, numbers.length - 1];
    while(index[0] < index[1] && index[1] < numbers.length) {
        curSum = numbers[index[0]] + numbers[index[1]];
        if(curSum > target) {
            index[1]--;
        } else if(curSum < target) {
            index[0]++;
        } else {
            break;
        }
    }

    return index.map(el => el + 1);
};