/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isIsomorphic = function(s, t) {
    const map = [new Map(), new Map()];
    for(let i = 0 ; i < s.length ; i++) {
        const tmp1 = map[0].get(s[i]);
        const tmp2 = map[1].get(t[i]);
        if(tmp1 || tmp2){
            if(tmp1 !== t[i] && tmp2 !== s[i]) {
                return false;
            }
        } else {
            map[0].set(s[i], t[i]);
            map[1].set(t[i], s[i]);
        }
    }

    return true;
};