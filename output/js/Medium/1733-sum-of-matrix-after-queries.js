/**https://leetcode.com/problems/sum-of-matrix-after-queries/ */
//You are given an integer n and a 0-indexed 2D array queries where queries[i] = [typei, indexi, vali].
//Initially, there is a 0-indexed n x n matrix filled with 0's. For each query, you must apply one of the following changes:
//	if typei == 0, set the values in the row with indexi to vali, overwriting any previous values.
//	if typei == 1, set the values in the column with indexi to vali, overwriting any previous values.
//Return the sum of integers in the matrix after all queries are applied.
// 
//Example 1:
//Input: n = 3, queries = [[0,0,1],[1,2,2],[0,2,3],[1,0,4]]
//Output: 23
//Explanation: The image above describes the matrix after each query. The sum of the matrix after all queries are applied is 23. 
//Example 2:
//Input: n = 3, queries = [[0,0,4],[0,1,2],[1,0,1],[0,2,3],[1,2,1]]
//Output: 17
//Explanation: The image above describes the matrix after each query. The sum of the matrix after all queries are applied is 17.
// 
//Constraints:
//	1 <= n <= 104
//	1 <= queries.length <= 5 * 104
//	queries[i].length == 3
//	0 <= typei <= 1
//	0 <= indexi < n
//	0 <= vali <= 105
/**
 * @param {number} n
 * @param {number[][]} queries
 * @return {number}
 */
var matrixSumQueries = function(n, queries) {
    let matrix = new Array(n);
    for (let i = 0; i < n; i++) {
        matrix[i] = new Array(n);
        for (let j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
    let m = queries.length;
    for (let i = 0; i < m; i++) {
        let type = queries[i][0];
        let index = queries[i][1];
        let val = queries[i][2];
        if (type === 0) {
            for (let j = 0; j < n; j++) {
                matrix[index][j] = val;
            }
        } else {
            for (let j = 0; j < n; j++) {
                matrix[j][index] = val;
            }
        }
    }
    let ans = 0;
    for (let i = 0; i < n; i++) {
        for (let j =0; j < n; j++) {
            ans += matrix[i][j]; 
        }
    }
    return ans;
};