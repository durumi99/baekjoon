function solution(number, k) {
    var answer = '';
    let str = number.split('');
    let idx = 0;
    while(k && idx < str.length) {
        let maxIdx = idx;
        let maxNum = str[idx];
        let minLen = Math.min(str.length, idx + k + 1);
        
        for(let i = idx + 1; i < minLen ; i++) {
            if(str[i] > maxNum) {
                maxIdx = i;
                maxNum = str[i];
            }
        }
        if(maxIdx == idx) {
            idx++;
        } else {
            k -= maxIdx - idx;
            str.splice(idx, maxIdx - idx);
        }
    }
    while(k) {
        str.pop();
        k--;
    }
    return str.join('');
}