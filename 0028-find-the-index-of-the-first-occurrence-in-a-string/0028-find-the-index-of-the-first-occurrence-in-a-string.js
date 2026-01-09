/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    for(let i = 0 ; i < haystack.length - needle.length + 1 ; i++) {
        let check = false;
        for(let j = 0 ; j < needle.length ; j++) {
            if(haystack[i + j] !== needle[j]) {
                check = true;
                break;
            }
        }
        if(!check) {
            return i;
        }
    }

    return -1;
};