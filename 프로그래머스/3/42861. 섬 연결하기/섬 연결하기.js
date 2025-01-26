const root = Array(101);

function find(x) {
    if(x == root[x])
        return x;
    
    return root[x] = find(root[x]);
}

function merge(x, y) {
    x = find(x);
    y = find(y);
    
    if(x == y)
        return;
    
    root[Math.max(x, y)] = Math.min(x, y);
}

function solution(n, costs) {
    var answer = 0;
    costs.sort((a, b) => a[2] - b[2]);
    
    for(let i = 0 ; i < n ; i++) {
        root[i] = i;
    }
    
    const s = new Set();
    for (const [nodeA, nodeB, cost] of costs) {
        if (find(nodeA) !== find(nodeB)) {
            
            merge(nodeA, nodeB);
            
            answer += cost;
            
            if(allConnected(n)) {
                break;
            }
        }
    }
    return answer;
}

function allConnected(n) {
    const tmp = root[0]; // 0번 노드 기준
    
    for (let i = 1; i < n; i++) {
        if (find(i) !== tmp) return false;
    }
    
    return true;
}