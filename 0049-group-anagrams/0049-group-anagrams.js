/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    const map = new Map();

    strs.forEach((str) => {
        const sortedStr = [...str].sort().join('');
        const tmp = map.get(sortedStr) || [];
        tmp.push(str);
        map.set(sortedStr, tmp);
    });

    return [...map.values()].sort((a, b) => a.length - b.length);
};