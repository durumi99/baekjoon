/**
 * @param {string} pattern
 * @param {string} s
 * @return {boolean}
 */
var wordPattern = function(pattern, s) {
    const arr = [[...pattern], s.split(' ')];
    const len = arr[0].length;
    if(len !== arr[1].length) {
        return false;
    }
    const checkPattern = (a, b) => {
        const map = new Map();
        for(let i = 0 ; i < len ; i++) {
            const tmp1 = a[i];
            const tmp2 = b[i];
            const check = map.get(tmp1);

            if(check) {
                if(check !== tmp2) {
                    return false;
                }
            } else {
                map.set(tmp1, tmp2);
            }
        }

        return true;    
    }

    return checkPattern(arr[0], arr[1]) && checkPattern(arr[1], arr[0]);
};