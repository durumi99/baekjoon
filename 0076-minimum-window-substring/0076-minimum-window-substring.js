/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var minWindow = function(s, t) {
    if (s.length < t.length) return "";

    // 1. Map 대신 정수 배열 사용 (ASCII 128)
    // 일반 Map보다 접근 속도가 압도적으로 빠름
    const map = new Int32Array(128); 
    let count = t.length; // 필요한 총 문자 개수
    
    // t의 문자 빈도수 기록
    for (let i = 0; i < t.length; i++) {
        map[t.charCodeAt(i)]++;
    }

    let minLen = Infinity;
    let minStart = 0;
    let left = 0;
    let right = 0;
    
    // s.length 프로퍼티 접근 비용 아끼기 위해 지역 변수화
    const sLen = s.length; 

    while (right < sLen) {
        // 2. 오른쪽 확장
        // s[right] 문자의 카운트를 깎음. 
        // 깎기 전 값이 0보다 컸다면, t에 포함된 '필요한 문자'를 찾았다는 뜻 -> count 감소
        if (map[s.charCodeAt(right++)]-- > 0) {
            count--;
        }

        // 3. 유효 윈도우 축소 (count가 0이면 모든 조건 만족 상태)
        while (count === 0) {
            // 현재 윈도우 길이 갱신 (right는 이미 1 증가된 상태이므로 right - left가 길이)
            if (right - left < minLen) {
                minLen = right - left;
                minStart = left;
            }

            // 4. 왼쪽 축소
            // s[left] 문자를 다시 뱉어냄 (카운트 증가)
            // 증가시킨 값이 0보다 커진다면(즉 1이 된다면), 방금 뱉은 게 '필요했던 문자'라는 뜻 -> count 증가 (조건 깨짐)
            if (map[s.charCodeAt(left++)]++ === 0) {
                count++;
            }
        }
    }

    return minLen === Infinity ? "" : s.substring(minStart, minStart + minLen);
};