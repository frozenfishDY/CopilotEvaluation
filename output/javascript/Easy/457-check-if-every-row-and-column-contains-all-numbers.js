/**https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/ */
//An n x n matrix is valid if every row and every column contains all the integers from 1 to n (inclusive).
//Given an n x n integer matrix matrix, return true if the matrix is valid. Otherwise, return false.
// 
//Example 1:
//Input: matrix = [[1,2,3],[3,1,2],[2,3,1]]
//Output: true
//Explanation: In this case, n = 3, and every row and column contains the numbers 1, 2, and 3.
//Hence, we return true.
//Example 2:
//Input: matrix = [[1,1,1],[1,2,3],[1,2,3]]
//Output: false
//Explanation: In this case, n = 3, but the first row and the first column do not contain the numbers 2 or 3.
//Hence, we return false.
// 
//Constraints:
//	n == matrix.length == matrix[i].length
//	1 <= n <= 100
//	1 <= matrix[i][j] <= n
/**
 * @param {number[][]} matrix
 * @return {boolean}
 */
var checkValid = function(matrix) {
    let n = matrix.length;
    let rows = new Array(n).fill(0);
    let cols = new Array(n).fill(0);
    for (let i = 0; i < n; i++) {
        rows[i] = new Set();
        cols[i] = new Set();
    }
    for (let i = 0; i < n; i++) {
        let row = rows[i];
        let col = cols[i];
        for (let j = 0; j < n; j++) {
            let num = matrix[i][j];
            if (num > n || num < 1) return false;
            if (row.has(num)) return false;
            row.add(num);
            if (col.has(num)) return false;
            col.add(num);
        }
    }
    return true;
};