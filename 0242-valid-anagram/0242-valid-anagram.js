/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    const arr = new Int16Array(128);
    if(s.length !== t.length) {
        return false;
    }
    for(let i = 0 ; i < s.length ; i++) {
        const char1 = s.charCodeAt(i);
        const char2 = t.charCodeAt(i);

        arr[char1]++;
        arr[char2]--;
        console.log(char1, char2, arr[char1], arr[char2])
    }
    console.log(arr['a'.charCodeAt()])
    console.log(arr['b'.charCodeAt()])
    
    return arr.every(el => el === 0);
};