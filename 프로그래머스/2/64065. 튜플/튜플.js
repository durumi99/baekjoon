function solution(s) {
    const MAX = 501;
    let answer = [];
    let v = Array.from({ length: MAX }, () => []);
    
    let v_size = 0;
    let tmp = [];
    
    for (let i = 0; i < s.length; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            let cur = i;
            while (cur < s.length && s[cur] >= '0' && s[cur] <= '9') {
                cur++;
            }
            tmp.push(parseInt(s.substring(i, cur), 10));
            i = cur - 1;
        } else if (s[i] === '}') {
            v_size++;
            v[tmp.length - 1] = [...tmp];
            tmp = [];
        }
    }
    v_size--;

    for (let i = 0; i < v_size; i++) {
        for (let j = 0; j < v[i].length; j++) {
            if (!answer.includes(v[i][j])) {
                answer.push(v[i][j]);
            }
        }
    }

    return answer;
}
