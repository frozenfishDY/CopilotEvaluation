/**https://leetcode.com/problems/01-matrix/ */
//Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
//The distance between two adjacent cells is 1.
// 
//Example 1:
//Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
//Output: [[0,0,0],[0,1,0],[0,0,0]]
//Example 2:
//Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
//Output: [[0,0,0],[0,1,0],[1,2,1]]
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 104
//	1 <= m * n <= 104
//	mat[i][j] is either 0 or 1.
//	There is at least one 0 in mat.
/**
 * @param {number[][]} mat
 * @return {number[][]}
 */
var updateMatrix = function(mat) {
    let result = [];
    for (let i = 0; i < mat.length; i++) {
        let row = mat[i];
        result.push([]);
        for (let j = 0; j < row.length; j++) {
            let cell = row[j];
            if (cell === 0) {
                result[i][j] = 0;
            } else {
                result[i][j] = Infinity;
            }
        }
    }
    for (let i = 0; i < mat.length; i++) {
        let row = mat[i];
        for (let j = 0; j < row.length; j++) {
            let cell = row[j];
            if (cell === 0) {
                result[i][j] = 0;
            } else {
                if (i > 0) {
                    result[i][j] = Math.min(result[i][j], result[i - 1][j] + 1);
                }
                if (j > 0) {
                    result[i][j] = Math.min(result[i][j], result[i][j - 1] + 1);
                }
            }
        }
    }
    for (let i = mat.length - 1; i >= 0; i--) {
        let row = mat[i];
        for (let j = row.length - 1; j >= 0; j--) {
            let cell = row[j];
            if (cell === 0) {
                result[i][j] = 0;
            } else {
                if (i < mat.length - 1) {
                    result[i][j] = Math.min(result[i][j], result[i + 1][j] + 1);
                }
                if (j < row.length - 1) {
                    result[i][j] = Math.min(result[i][j], result[i][j + 1] + 1);
                }
            }
        }
    }
    return result;
};