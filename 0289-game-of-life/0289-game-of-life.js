/**
 * @param {number[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var gameOfLife = function(board) {
    const m = board.length;
    const n = board[0].length;
    const dy = [-1, -1, -1, 0, 0, 1, 1, 1];
    const dx = [-1, 0, 1, -1, 1, -1, 0, 1];

    const getNeighborsCount = (y, x) => {
        let cnt = 0;

        for(let i = 0 ; i < 8 ; i++) {
            const ny = y + dy[i];
            const nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= m || nx >=n){
                continue;
            }

            if(board[ny][nx]) {
                cnt++;
            }
        }

        return cnt;
    }

    const checkLiveCell = (cnt) => {
        if(cnt < 2) {
            return false;
        } 

        if(cnt === 2 || cnt === 3) {
            return true;
        }

        if(cnt > 3) {
            return false;
        }
    }

    const checkDeadCell = (cnt) => {
        return cnt === 3;
    }

    const checkCell = (live, cnt) => {
        return live === 1 ? checkLiveCell(cnt) : checkDeadCell(cnt);
    }

    const results = [];
    for(let i = 0 ; i < m ; i++) {
        for(let j = 0 ; j < n ; j++) {
            const cnt = getNeighborsCount(i, j);
            const checkResult = checkCell(board[i][j], cnt);
            checkResult ? results.push(1) : results.push(0);
        }
    }
    
    for(let i = 0 ; i < m ; i++) {
        for(let j = 0 ; j < n ; j++) {
            board[i][j] = results[i * n + j];
        }
    }
};