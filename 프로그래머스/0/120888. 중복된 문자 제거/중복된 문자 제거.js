function solution(my_string) {
    const s = new Set();
    var answer = [...my_string].filter((el) => {
        if(!s.has(el)) {
            s.add(el);
            return true;
        }
        
        return false;
    }).join('');
    return answer;
}