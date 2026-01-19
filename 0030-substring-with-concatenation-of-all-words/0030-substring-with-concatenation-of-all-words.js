/**
 * @param {string} s
 * @param {string[]} words
 * @return {number[]}
 */
var findSubstring = function(s, words) {
    const length = words[0].length;
    const wordMap = new Map();
    words.forEach((word)=>{
        wordMap.set(word, (wordMap.get(word) || 0) + 1);
    })
    const result = [];

    const check = (idx) => {
        const curWordMap = new Map();
        const init = idx;
        while(idx < init + words.length * length) {
            const cur = s.slice(idx, idx + length);
            idx += length;
            const cnt = wordMap.get(cur);
            const curCnt = curWordMap.get(cur) || 0;

            if(!cnt || curCnt >= cnt) {
                return false;
            }

            curWordMap.set(cur, curCnt + 1);
        }
        
        return areMapsEqual(curWordMap, wordMap);
    }

    for(let i = 0 ; i < s.length ; i++) {
        if(check(i)) {
            result.push(i);
        }
    }

    return result;
};

function areMapsEqual(map1, map2) {
  if (map1.size !== map2.size) {
    return false;
  }

  for (const [key, value] of map1) {
    if (!map2.has(key) || map2.get(key) !== value) {
      return false;
    }
  }

  return true;
}