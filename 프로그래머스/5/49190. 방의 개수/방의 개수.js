const dy = [-1, -1, 0, 1, 1, 1, 0, -1];
const dx = [0, 1, 1, 1, 0, -1, -1, -1];

function solution(arrows) {
    var answer = 0;
    let y =  0;
    let x =  0;
    
    const visited = new Set(); 
    const visitedPath = new Set(); 
    visited.add(`${y},${x}`);
    
    arrows.forEach((arrow) => {
        for (let i = 0; i < 2; i++) { 
            const ny = y + dy[arrow];
            const nx = x + dx[arrow];

            if (visited.has(`${ny},${nx}`) && !visitedPath.has(`${y},${x},${ny},${nx}`)) {
                answer++;
            }

            visited.add(`${ny},${nx}`);
            visitedPath.add(`${y},${x},${ny},${nx}`);
            visitedPath.add(`${ny},${nx},${y},${x}`);

            y = ny;
            x = nx;
        }
    });
    
    return answer;
}