/**https://leetcode.com/problems/increment-submatrices-by-one/ */
//You are given a positive integer n, indicating that we initially have an n x n 0-indexed integer matrix mat filled with zeroes.
//You are also given a 2D integer array query. For each query[i] = [row1i, col1i, row2i, col2i], you should do the following operation:
//Add 1 to every element in the submatrix with the top left corner (row1i, col1i) and the bottom right corner (row2i, col2i). That is, add 1 to mat[x][y] for for all row1i <= x <= row2i and col1i <= y <= col2i.
//Return the matrix mat after performing every query.


/**
 * @param {number} n
 * @param {number[][]} queries
 * @return {number[][]}
 */
var rangeAddQueries = function(n, queries) {
    let result = new Array(n).fill(0);
    for(let i = 0; i < n; i++){
        result[i] = new Array(n).fill(0);
    }
    for(let i = 0; i < queries.length; i++){
        let query = queries[i];
        let row1 = query[0];
        let col1 = query[1];
        let row2 = query[2];
        let col2 = query[3];
        result[row1][col1]++;
        if(row2 + 1 < n){
            result[row2 + 1][col1]--;
        }
        if(col2 + 1 < n){
            result[row1][col2 + 1]--;
        }
        if(row2 + 1 < n && col2 + 1 < n){
            result[row2 + 1][col2 + 1]++;
        }
    }
    for(let i = 0; i < n; i++){
        for(let j = 0; j < n; j++){
            if(i > 0){
                result[i][j] += result[i - 1][j];
            }
            if(j > 0){
                result[i][j] += result[i][j - 1];
            }
            if(i > 0 && j > 0){
                result[i][j] -= result[i - 1][j - 1];
            }
        }
    }
    return result;
    
};

    