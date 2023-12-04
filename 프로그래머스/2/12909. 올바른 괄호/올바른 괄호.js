function solution(s) {
    let answer = true;

    const stack = [];
    for (const it of s) {
        if (it === '(') {
            stack.push(it);
        } else {
            if (stack.length === 0) {
                answer = false;
                break;
            } else {
                stack.pop();
            }
        }
    }

    if (stack.length !== 0) {
        answer = false;
    }
    return answer;
}

// 테스트
const result = solution("((())())");
console.log(result); // true
