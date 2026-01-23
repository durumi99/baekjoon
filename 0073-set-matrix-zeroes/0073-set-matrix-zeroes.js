/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var setZeroes = function(matrix) {
    const m = matrix.length;
    const n = matrix[0].length;
    const zeros = [];
    for (let i = 0 ; i < m ; i++) {
        for (let j = 0 ; j < n ; j++) {
            if(matrix[i][j] === 0) {
                zeros.push({y : i, x : j});
            }
        }
    }

    zeros.forEach(({y, x}) => {
        for(let i = 0 ; i < m ; i++) {
            matrix[i][x] = 0;
        }
        for(let i = 0 ; i < n ; i++) {
            matrix[y][i] = 0;
        }
    })
};