/**https://leetcode.com/problems/count-submatrices-with-all-ones/ */
//Given an m x n binary matrix mat, return the number of submatrices that have all ones.
// 
//Example 1:
//Input: mat = [[1,0,1],[1,1,0],[1,1,0]]
//Output: 13
//Explanation: 
//There are 6 rectangles of side 1x1.
//There are 2 rectangles of side 1x2.
//There are 3 rectangles of side 2x1.
//There is 1 rectangle of side 2x2. 
//There is 1 rectangle of side 3x1.
//Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.
//Example 2:
//Input: mat = [[0,1,1,0],[0,1,1,1],[1,1,1,0]]
//Output: 24
//Explanation: 
//There are 8 rectangles of side 1x1.
//There are 5 rectangles of side 1x2.
//There are 2 rectangles of side 1x3. 
//There are 4 rectangles of side 2x1.
//There are 2 rectangles of side 2x2. 
//There are 2 rectangles of side 3x1. 
//There is 1 rectangle of side 3x2. 
//Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24.
// 
//Constraints:
//	1 <= m, n <= 150
//	mat[i][j] is either 0 or 1.
/**
 * @param {number[][]} mat
 * @return {number}
 */
var numSubmat = function(mat) {
    let m = mat.length;
    let n = mat[0].length;
    let result = 0;
    let height = Array.from({length: m}, () => new Array(n).fill(0));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++){
            if (mat[i][j] === 0) {
                height[i][j] = 0;
            } else {
                height[i][j] = i === 0 ? 1 : height[i - 1][j] + 1;
            }
        }
    }
    for (let i = 0; i < m; i++) {
        let stack = [];
        let sum = 0;
        for (let j = 0; j <= n; j++) {
            let cur = j === n ? -1 : height[i][j];
            while (stack.length > 0 && cur <= height[i][stack[stack.length - 1]]) {
                let h = height[i][stack.pop()];
                let w = stack.length === 0 ? j : j - stack[stack.length - 1] - 1;
                sum += h * w;
            }
            stack.push(j);
        }
        result += sum;
    }
    return result;
};