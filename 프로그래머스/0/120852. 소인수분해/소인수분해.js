function solution(n) {
    var answer = [];
    const s = new Set();
    let num = 2;
    while(n !== 1) {
        while(n % num === 0) {
            n /= num;
            s.add(num);
        }
        num++;
    }  
    answer = [...s];
    return answer;
}