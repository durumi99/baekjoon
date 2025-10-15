function solution(array, n) {
    var answer = array.reduce((acc, el) => {
        if(Math.abs(n - el) < Math.abs(n - acc)) {
            acc = el;
        } else if (n - el === acc - n && el < n) {
            acc = el;
        }
        
        return acc;
    }, Infinity);
    return answer;
}