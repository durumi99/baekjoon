/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
function checkCondition(map1, map2) {
  for (const [key, value] of map1) {
    if (!map2.has(key) || map2.get(key) < value) {
      return false;
    }
  }

  return true;
}
var minWindow = function(s, t) {
    if(t.length > s.length){
        return '';
    }
    if(t.length === 1){
        return s.indexOf(t) === -1 ? '' : t;
    }
    let left = 0;
    let right = 0;
    let curLength = s.length + 1;
    let answer = "";
    const map = new Map();
    [...t].forEach((el)=> {
        map.set(el, (map.get(el) || 0) + 1);
    });
    const curMap = new Map();
    curMap.set(s[0], 1);

    while(left <= right && right < s.length) {
        while(!checkCondition(map, curMap) && right < s.length) {
            right++;
            curMap.set(s[right], (curMap.get(s[right]) || 0) + 1);
        }
        while(checkCondition(map, curMap)) {
            curMap.set(s[left], curMap.get(s[left]) - 1);
            left++;
        }
        if(curLength > right - left + 2) {
            curLength = right - left + 2;
            answer = s.slice(left - 1, right + 1);
        }
    }

    return answer;
};