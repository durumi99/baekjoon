function solution(s) {
    var answer = '';
    const m = new Map();
    [...s].forEach((el) => {
        m.set(el, (m.get(el) || 0) + 1);
    });
    for(const [k, v] of m) {
        if(v === 1) {
            answer += k;
        }
    }
    return [...answer].sort().join('');
}