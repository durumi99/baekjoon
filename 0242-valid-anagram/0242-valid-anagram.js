/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    const arr = new Int8Array(128);
    if(s.length !== t.length) {
        return false;
    }
    for(let i = 0 ; i < s.length ; i++) {
        const char1 = s.charCodeAt(i);
        const char2 = t.charCodeAt(i);

        arr[char1]++;
        arr[char2]--;
    }

    return arr.every(el => el === 0);
};