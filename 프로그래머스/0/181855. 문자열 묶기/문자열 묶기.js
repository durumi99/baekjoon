function solution(strArr) {
    const map = new Map();
    strArr.forEach((el) => {
        map.set(el.length, (map.get(el.length) || 0) + 1);
    })
    var answer = Math.max(...map.values());
    return answer;
}