/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    const arr = s.trim(' ').split(' ');
    return arr.at(-1).length;
};