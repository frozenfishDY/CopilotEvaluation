/**https://leetcode.com/problems/diagonal-traverse/ */
//Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.
// 
//Example 1:
//Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [1,2,4,7,5,3,6,8,9]
//Example 2:
//Input: mat = [[1,2],[3,4]]
//Output: [1,2,3,4]
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 104
//	1 <= m * n <= 104
//	-105 <= mat[i][j] <= 105
/**
 * @param {number[][]} mat
 * @return {number[]}
 */
var findDiagonalOrder = function(mat) {
    let result = [];
    let m = mat.length;
    let n = mat[0].length;
    let i = 0;
    let j = 0;
    let direction = 1;
    while (result.length < m * n) {
        result.push(mat[i][j]);
        if (direction === 1) {
            if (j === n - 1) {
                direction = -1;
                i++;
            } else if (i === 0) {
                direction = -1;
                j++;
            } else {
                i--;
                j++;
            }
        } else {
            if (i === m - 1) {
                direction = 1;
                j++;
            } else if (j === 0) {
                direction = 1;
                i++;
            } else {
                i++;
                j--;
            }
        }
    }
    return result;
};