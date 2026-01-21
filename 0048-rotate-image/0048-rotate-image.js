/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    const n = matrix.length;
    const origin = Array.from({length : n}, () => new Array(n));
    for(let i = 0 ; i < n ; i++) {
        for(let j = 0; j < n; j++) { 
            origin[i][j] = matrix[i][j];
        }
    }
    for(let i = 0 ; i < n ; i++) {
        for(let j = 0; j < n; j++) {
            const y = j;
            const x = n - i - 1;
            matrix[y][x] = origin[i][j];
        }
    }
};