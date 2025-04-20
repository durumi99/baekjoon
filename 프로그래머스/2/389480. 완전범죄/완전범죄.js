function solution(info, n, m) {
    var answer = -1;
    const rate = info.map((el) => [...el, el[0] / el[1]]).sort((a, b) => b[2] - a[2] || b[1] - a[1]);
    const visited = Array(rate.length).fill(false);
    
    let a = 0, b = 0;
    
    rate.forEach((el, idx) => {
        if(b + el[1] < m) {
            b += el[1];
            visited[idx] = true;
        }
    });
    
    rate.forEach((el, idx) => {
        if(visited[idx]) {
            return;
        }
        
        if(a + el[0] < n) {
            a += el[0];
            visited[idx] = true;
        }
    });
    
    if(visited.some((el) => !el)) {
        return -1;
    }
    return a;
}