/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    const regexp = /[A-Z\d]/gi;
    const arr = s.toLowerCase().match(regexp) || [];
    
    for(let i = 0 ; i < arr.length / 2 ; i++) {
        if(arr[i] !== arr[arr.length - 1 - i]) {
            return false;
        }
    }

    return true;
};