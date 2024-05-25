
function solution(elements) {
    var answer = 0;
    const len = elements.length;
    let s = new Set();
    for(let i = 0 ; i < len ; i++) {
        let sum = elements[i];
        s.add(sum);
        let j = 1;
        while(j < len) {
            sum += elements[(i + j) % len];
            s.add(sum);
            j++;
        }
    }
    answer = s.size;
    return answer;
}