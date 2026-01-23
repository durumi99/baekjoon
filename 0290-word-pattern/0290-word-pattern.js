/**
 * @param {string} pattern
 * @param {string} s
 * @return {boolean}
 */
var wordPattern = function(pattern, s) {
    const arr = s.split(' ');
    const len = pattern.length;
    if(len !== arr.length) {
        return false;
    }

   
    const mapP = Object.create(null);
    const mapS = Object.create(null);
    
    for(let i = 0 ; i < len ; i++) {
        const charP = pattern[i];
        const wordS = arr[i];
        
        if (mapP[charP] !== mapS[wordS]) {
            return false;
        }

        mapP[charP] = i + 1;
        mapS[wordS] = i + 1;
    }

    return true;    
};