function solution(N, road, K) {
    var answer = 0;

    const dist = Array.from({length : N + 1}, () => 99999999);
    dist[1] = 0;
    const map = Array.from({length : N + 1}, () => []);
    
    road.forEach(([a, b, c]) => {
        map[a].push([b, c]);
        map[b].push([a, c]);
    });
    
    const q = [];
    q.push(1);
    
    while(q.length > 0) {
        const cur = q.shift();
        
        for(let i = 0 ; i < map[cur].length ; i++) {
            const b = map[cur][i][0];
            const c = map[cur][i][1];
            if(dist[b] > dist[cur] + c) {
                dist[b] = dist[cur] + c;
                q.push(b);
            }
        }
    }
    answer = dist.reduce((acc, el) => {
        if(el <= K) {
            acc++;
        }
        
        return acc;
    }, 0);
    return answer;
}