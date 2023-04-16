/**https://leetcode.com/problems/largest-submatrix-with-rearrangements/ */
//You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.
//Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.


/**
 * @param {number[][]} matrix
 * @return {number}
 */
var largestSubmatrix = function(matrix) {
    let m = matrix.length;
    let n = matrix[0].length;
    let heights = new Array(n).fill(0);
    let result = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                heights[j] = 0;
            } else {
                heights[j]++;
            }
        }
        let sorted = heights.slice();
        sorted.sort((a, b) => a - b);
        for (let j = 0; j < n; j++) {
            result = Math.max(result, sorted[j] * (n - j));
        }
    }
    return result;
    
};

    