/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var minWindow = function(s, t) {
    if (t.length > s.length) return '';

    const targetMap = new Map();
    for (const char of t) {
        targetMap.set(char, (targetMap.get(char) || 0) + 1);
    }

    let left = 0;
    let right = 0;
    let formed = 0; // 현재 조건을 만족한 고유 문자의 개수
    const required = targetMap.size; // 만족해야 할 고유 문자의 총 개수
    
    const windowMap = new Map();
    
    // 결과 저장용 (길이, 시작인덱스) - 초기값은 무한대
    let minLen = Infinity; 
    let minStart = 0;

    while (right < s.length) {
        const char = s[right];
        windowMap.set(char, (windowMap.get(char) || 0) + 1);

        // 현재 문자의 개수가 타겟의 개수와 "정확히" 일치하게 되는 순간 formed 증가
        if (targetMap.has(char) && windowMap.get(char) === targetMap.get(char)) {
            formed++;
        }

        // 모든 조건을 만족하는 동안 left를 줄여나감 (윈도우 축소)
        while (left <= right && formed === required) {
            // 최소 길이 갱신 (slice는 안함)
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minStart = left;
            }

            // left 문자 제거
            const leftChar = s[left];
            windowMap.set(leftChar, windowMap.get(leftChar) - 1);

            // 제거로 인해 조건을 불만족하게 되면 formed 감소
            if (targetMap.has(leftChar) && windowMap.get(leftChar) < targetMap.get(leftChar)) {
                formed--;
            }
            
            left++;
        }
        
        right++;
    }

    return minLen === Infinity ? "" : s.slice(minStart, minStart + minLen);
};