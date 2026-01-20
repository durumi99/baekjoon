/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    const m = matrix.length;
    const n = matrix[0].length;
    const dy = [0, 1, 0, -1];
    const dx = [1, 0, -1, 0];
    let dir = 0;
    let y = 0, x = 0;
    const answer = [];
    const visit = Array.from({ length: m }, () => new Int16Array(n));

    while(answer.length < m * n) {
        answer.push(matrix[y][x]);
        visit[y][x]++;
        let nY = y + dy[dir];
        let nX = x + dx[dir];
        if(nY < 0 || nX < 0 || nY >= m || nX >= n || visit[nY][nX]) {
            dir = (dir + 1) % 4;
            nY = y + dy[dir];
            nX = x + dx[dir];
        }
        y = nY;
        x = nX;
    }

    return answer;
};