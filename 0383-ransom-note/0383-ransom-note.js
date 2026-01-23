/**
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
var canConstruct = function(ransomNote, magazine) {
    const map = new Map();
    [...magazine].forEach((el) => {
        map.set((el), (map.get(el) || 0) + 1);
    });

    return [...ransomNote].every((el) => {
        if (map.get(el) > 0) {
            map.set(el, map.get(el) - 1);
            
            return true;
        }

        return false;
    });
};