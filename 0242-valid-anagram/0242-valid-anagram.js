/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    const arr = new Int16Array(26);
    const charCodeA = 'a'.charCodeAt();
    if(s.length !== t.length) {
        return false;
    }
    for(let i = 0 ; i < s.length ; i++) {
        const char1 = s.charCodeAt(i) - charCodeA;
        const char2 = t.charCodeAt(i) - charCodeA;

        arr[char1]++;
        arr[char2]--;
    }
    
    return arr.every(el => el === 0);
};