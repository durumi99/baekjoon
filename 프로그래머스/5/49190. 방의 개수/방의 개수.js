const dy = [-1, -1, 0, 1, 1, 1, 0, -1];
const dx = [0, 1, 1, 1, 0, -1, -1, -1];

function solution(arrows) {
    const n = 1000000;
    var answer = 0;
    let y =  0;
    let x =  0;
    
    const visited = new Set(); // 방문한 노드
    const visitedPath = new Set(); 
    visited.add(`${y},${x}`);
    
    arrows.forEach((arrow) => {
        for (let i = 0; i < 2; i++) { // 대각선 이동 시 끊기지 않게 2번 반복
            const ny = y + dy[arrow];
            const nx = x + dx[arrow];

            // 노드 방문 여부 확인
            if (visited.has(`${ny},${nx}`) && !visitedPath.has(`${y},${x},${ny},${nx}`)) {
                answer++;
            }

            // 경로 방문 체크 (양방향)
            visited.add(`${ny},${nx}`);
            visitedPath.add(`${y},${x},${ny},${nx}`);
            visitedPath.add(`${ny},${nx},${y},${x}`);

            y = ny;
            x = nx;
        }
    });
    
    return answer;
}