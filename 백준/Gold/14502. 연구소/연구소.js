const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');


const dy = [-1, 0, 0, 1];
const dx = [0, -1, 1, 0];

const [N, M] = input[0].split(' ').map(Number);
const graph = input.slice(1).map(line => line.split(' ').map(Number));
let answer = 0;


const dfs = (cnt) => {
    if(cnt === 0) {
        getVirusArea();
        return;
    }
    
    for (let i = 0 ; i < N ; i++) {
        for(let j = 0 ; j < M ; j++) {
            if(graph[i][j] === 0) {
                graph[i][j] = 1;
                dfs(cnt - 1);
                graph[i][j] = 0;
            }
        }
    }
}

const getVirusArea = () => {
    const tempGraph = graph.map(row => [...row]);
    
    for (let i = 0 ; i < N ; i++) {
        for(let j = 0 ; j < M ; j++) {
            if(tempGraph[i][j] === 2) {
                const q = [];
                q.push([i, j]);
                
                while(q.length) {
                    const [y, x] = q.at(-1);
                    q.pop();
                    
                    for(let k = 0 ; k < 4 ;  k++) {
                        const nY = y + dy[k];
                        const nX = x + dx[k];
                        
                        if(nY < 0 || nY >= N || nX < 0 || nX >= M)
                            continue;
                            
                        if(tempGraph[nY][nX] === 0) {
                            tempGraph[nY][nX] = 2;
                            q.push([nY, nX]);
                        }
                    }
                }
            }
        }
    }
    
    const cnt = tempGraph.flat().filter((el) => el === 0).length;
    answer = Math.max(cnt, answer);
}

dfs(3);
console.log(answer);
