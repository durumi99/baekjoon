/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function(board) {
    const colCheck = (row) => {
        const set = new Set();
        for(let i = 0 ; i < 9; i++) {
            if(board[row][i] === ".") {
                continue;
            }
            if(!set.has(board[row][i]))  {
                set.add(board[row][i]);
            } else {
                return false;
            }
        }

        return true;
    }

    const rowCheck = (col) => {
        const set = new Set();
        for(let i = 0 ; i < 9; i++) {
            if(board[i][col] === ".") {
                continue;
            }
            if(!set.has(board[i][col]))  {
                set.add(board[i][col]);
            } else {
                return false;
            }
        }

        return true;
    }

    const boxCheck = (row, col) => {
        const set = new Set();
        for(let i = 0 ; i < 3 ; i++) {
            for(let j = 0 ; j < 3 ; j++) {
                if(board[row + i][col + j] === ".") {
                    continue;
                }
                if(!set.has(board[row + i][col + j]))  {
                    set.add(board[row + i][col + j]);
                } else {
                    return false;
                }
            }
        }

        return true;
    }

    for(let i = 0 ; i < 9 ; i++) {
        const row = Math.floor(i / 3) * 3;
        const col = i % 3 * 3;
        if(!colCheck(i) || !rowCheck(i) || !boxCheck(row, col)) {
            return false;
        }
    }

    return true;
};