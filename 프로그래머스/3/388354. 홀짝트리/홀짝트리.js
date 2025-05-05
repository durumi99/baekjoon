function solution(nodes, edges) {
    const maxNode = 1000000;
    const degree = new Array(maxNode + 1).fill(0);

    for (let [u, v] of edges) {
        degree[u]++;
        degree[v]++;
    }

    const graph = Array.from({ length: maxNode + 1 }, () => []);
    for (let [u, v] of edges) {
        graph[u].push(v);
        graph[v].push(u);
    }

    const visited = new Array(maxNode + 1).fill(false);
    let oddEvenTreeCount = 0;
    let reverseOddEvenTreeCount = 0;

    for (const node of nodes) {
        if (visited[node]) continue;

        const queue = [node];
        visited[node] = true;
        let matchCount = 0;
        let totalNodes = 0;

        while (queue.length) {
            const curr = queue.shift();
            totalNodes++;

            const valueParity = curr % 2;
            const degreeParity = degree[curr] % 2;
            if (valueParity === degreeParity) matchCount++;

            for (const neighbor of graph[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.push(neighbor);
                }
            }
        }

        const mismatchCount = totalNodes - matchCount;

        if (matchCount === 1) oddEvenTreeCount++;
        if (mismatchCount === 1) reverseOddEvenTreeCount++;
    }

    return [oddEvenTreeCount, reverseOddEvenTreeCount];
}