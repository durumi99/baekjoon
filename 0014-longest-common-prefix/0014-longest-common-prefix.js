/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    let result = "";
    let tmp = 0;
    while(tmp < strs[0].length) {
        let check = true;
        for(let i = 1 ; i < strs.length ; i++) {
            if(strs[0][tmp] !== strs[i][tmp]) {
                check = false;
                break;
            }
        }
        if(!check) {
            break;
        }
        result += strs[0][tmp];
        tmp++;
    }

    return result;
};