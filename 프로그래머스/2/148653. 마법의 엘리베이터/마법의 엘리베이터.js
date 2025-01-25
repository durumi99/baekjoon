function solution(storey) {
    var answer = 99999999;
    const q = [];
    q.push([storey, 0]);
    
    while(q.length) {
        const [curStorey, curCnt] = q.shift();
        if(answer <= curCnt) {
            continue;
        }
        
        if(curStorey === 0) {
            
            answer = Math.min(answer, curCnt);
            continue;
        }
        
        const tmp = curStorey % 10;
        q.push([(curStorey - tmp) / 10, curCnt + tmp]);
        q.push([(curStorey - tmp + 10) / 10, curCnt + 10 - tmp]);
    }
    return answer;
}