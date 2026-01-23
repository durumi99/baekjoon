/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    if (s.length !== t.length) return false;

    // 1. 일반 배열이 V8 엔진에서 작은 고정 크기(26)일 때 매우 빠름
    // (Int32Array를 써도 무방함)
    const table = new Int32Array(26); 
    
    // 'a'의 charCode는 97. 매번 구하지 않고 상수로 생각하거나 변수 캐싱
    // 루프 안에서 - 'a'.charCodeAt() 하는 것보다 - 97이 미세하게 빠름
    
    // 2. 첫 번째 문자열 카운팅 (Pass 1)
    for (let i = 0; i < s.length; i++) {
        table[s.charCodeAt(i) - 97]++;
    }

    // 3. 두 번째 문자열 차감 & 즉시 검증 (Pass 2)
    for (let i = 0; i < t.length; i++) {
        const idx = t.charCodeAt(i) - 97;
        
        // table[idx]를 1 줄였는데 0보다 작다? 
        // -> s에는 없는데 t에 더 많다는 뜻 -> 즉시 탈락
        if (--table[idx] < 0) {
            return false;
        }
    }

    // 길이가 같은데 위 루프를 통과했다면, 모든 값이 0일 수밖에 없음
    return true;
};