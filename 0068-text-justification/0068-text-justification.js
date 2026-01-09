/**
 * @param {string[]} words
 * @param {number} maxWidth
 * @return {string[]}
 */

// 1. 공백 분배 로직을 더 안전하고 함수형으로 개선
function formatWords(words, maxWidth) {
    // 단어가 하나거나 마지막 줄 처리를 위해 호출된 경우 (여기서는 단어 하나일 때만 사용됨)
    if (words.length === 1) {
        return words[0] + ' '.repeat(maxWidth - words[0].length);
    }

    const totalChars = words.join('').length;
    const totalSpaces = maxWidth - totalChars;
    const gaps = words.length - 1;

    // 기본적으로 들어갈 공백 개수 (정수)
    const baseSpaceCount = Math.floor(totalSpaces / gaps);
    // 왼쪽부터 하나씩 더 챙겨가야 할 나머지 공백 개수
    let extraSpaces = totalSpaces % gaps;

    return words.reduce((line, word, idx) => {
        if (idx === words.length - 1) return line + word; // 마지막 단어 뒤엔 공백 없음
        
        // base + (나머지가 남아있으면 1개 추가)
        const currentSpace = baseSpaceCount + (extraSpaces-- > 0 ? 1 : 0);
        return line + word + ' '.repeat(currentSpace);
    }, "");
}

var fullJustify = function(words, maxWidth) {
    const output = [];
    let curWords = [];
    let curWidth = 0;

    for (let word of words) {
        // 2. 현재 단어를 넣었을 때 길이 계산 (기존 단어들 + 사이 공백들 + 새 단어)
        // curWords.length가 공백의 개수와 같습니다 (단어 2개면 공백 1개 필요)
        if (curWidth + curWords.length + word.length <= maxWidth) {
            curWords.push(word);
            curWidth += word.length;
        } else {
            // 3. 넘치면 기존 단어들을 정렬해서 출력
            output.push(formatWords(curWords, maxWidth));
            curWords = [word];
            curWidth = word.length;
        }
    }

    // 4. 마지막 줄 처리 (왼쪽 정렬)
    if (curWords.length > 0) {
        const lastLine = curWords.join(' ');
        output.push(lastLine + ' '.repeat(maxWidth - lastLine.length));
    }

    return output;
};