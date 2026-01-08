/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
    // 순서가 중요하므로 배열에 정의 (큰 수 -> 작은 수)
    const romanMap = [
        { val: 1000, sym: 'M' },
        { val: 900, sym: 'CM' },
        { val: 500, sym: 'D' },
        { val: 400, sym: 'CD' },
        { val: 100, sym: 'C' },
        { val: 90, sym: 'XC' },
        { val: 50, sym: 'L' },
        { val: 40, sym: 'XL' },
        { val: 10, sym: 'X' },
        { val: 9, sym: 'IX' },
        { val: 5, sym: 'V' },
        { val: 4, sym: 'IV' },
        { val: 1, sym: 'I' }
    ];

    let result = "";

    for (const { val, sym } of romanMap) {
        // 현재 값보다 num이 작으면 계산할 필요 없이 넘어감 (최적화)
        if (num < val) continue;

        // 1. 몇 번 반복되는지 몫을 구함
        const count = Math.floor(num / val);
        
        // 2. 몫만큼 심볼 반복 추가
        result += sym.repeat(count);
        
        // 3. 나머지를 다시 num에 할당
        num %= val;
    }

    return result;
};