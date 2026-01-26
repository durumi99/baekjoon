/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    const map = {};

    strs.forEach((str) => {
        const sortedStr = [...str].sort().join('');
        const tmp = map[sortedStr] || [];
        tmp.push(str);
        map[sortedStr] = tmp;
    });

    return Object.values(map).sort((a, b) => a.length - b.length);
};