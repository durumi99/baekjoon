const dy = [-1, 1, 0, 0];
const dx = [0, 0, -1, 1];

function solution(land) {
    const rows = land.length;
    const cols = land[0].length;
    const visited = Array.from({ length: rows }, () => Array(cols).fill(false));
    const sectionMap = {};  // { sectionId: 해당 섹션의 총 기름양 }
    let sectionId = 1;

    // 🔹 BFS로 영역별 석유량 계산
    function bfs(y, x) {
        const queue = [[y, x]];
        visited[y][x] = sectionId;
        let count = 0;
        let positions = [[y, x]];

        while (queue.length) {
            const [cy, cx] = queue.shift();
            count++;

            for (let i = 0; i < 4; i++) {
                const ny = cy + dy[i];
                const nx = cx + dx[i];

                if (ny < 0 || nx < 0 || ny >= rows || nx >= cols) continue;
                if (visited[ny][nx] || land[ny][nx] === 0) continue;

                visited[ny][nx] = sectionId;
                queue.push([ny, nx]);
                positions.push([ny, nx]);
            }
        }

        // 🔹 석유량을 저장하고, 해당 섹션에 속한 모든 좌표에 동일한 값 저장
        sectionMap[sectionId] = count;
        positions.forEach(([y, x]) => {
            visited[y][x] = sectionId;  // 동일한 섹션 ID로 표시
        });

        sectionId++;
    }

    // 🔹 전체 지도 탐색하며 BFS 수행 (중복 탐색 방지)
    for (let y = 0; y < rows; y++) {
        for (let x = 0; x < cols; x++) {
            if (land[y][x] === 1 && !visited[y][x]) {
                bfs(y, x);
            }
        }
    }

    let maxOil = 0;

    // 🔹 각 열(column)에서 최대 석유량 계산
    for (let x = 0; x < cols; x++) {
        let columnOil = 0;
        const countedSections = new Set();

        for (let y = 0; y < rows; y++) {
            const secId = visited[y][x];
            if (secId && !countedSections.has(secId)) {
                columnOil += sectionMap[secId];
                countedSections.add(secId);
            }
        }

        maxOil = Math.max(maxOil, columnOil);
    }

    return maxOil;
}