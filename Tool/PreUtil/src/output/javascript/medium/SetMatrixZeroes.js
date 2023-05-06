/**https://leetcode.com/problems/set-matrix-zeroes/ */
//Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
//You must do it in place.


/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var setZeroes = function(matrix) {
    let m = matrix.length;
    let n = matrix[0].length;
    let rows = new Set();
    let cols = new Set();
    for(let i = 0; i < m; i++){
        for(let j = 0; j < n; j++){
            if(matrix[i][j] == 0){
                rows.add(i);
                cols.add(j);
            }
        }
    }
    for(let i = 0; i < m; i++){
        for(let j = 0; j < n; j++){
            if(rows.has(i) || cols.has(j)){
                matrix[i][j] = 0;
            }
        }
    }
    
    
};

    