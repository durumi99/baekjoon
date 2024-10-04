function solution(x, y, n) {
    var answer = -1;
    if(y < x) {
        return answer;
    }
    let q = [];
    let visited = new Array(y + 1).fill(false);
    q.push([y, 0]);
    while(q.length) {
        const curN = q[0][0];
        const curCnt = q[0][1];
        q.shift();
        visited[curN] = true;
        if(curN == x) {
            answer = curCnt;
            break;
        }
        
        const nextNs = [curN - n, curN / 2, curN / 3];
        for(const nextN of nextNs) {
            if(nextN >= x && Math.round(nextN) === nextN && !visited[nextN])
                q.push([nextN, curCnt + 1]);
        }
    }
    
    return answer;
}