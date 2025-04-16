function solution(n, roads, sources, destination) {
    var answer = [];
    const roadMaps = Array.from({ length: n + 1 }, () => []);
    const distance = new Array(n + 1).fill(-1);
    
    roads.forEach(([a, b]) => {
        roadMaps[a].push(b);
        roadMaps[b].push(a);
    })
    
     // 목적지에서 출발해 BFS로 모든 노드까지 최소 거리 계산
    const q = [destination];
    distance[destination] = 0;

    while (q.length) {
        const current = q.shift();

        for (const next of roadMaps[current]) {
            if (distance[next] === -1) {
                distance[next] = distance[current] + 1;
                q.push(next);
            }
        }
    }

    // sources 배열 순회하며 거리 참조
    return sources.map(src => distance[src]);
    return answer;
}