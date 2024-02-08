/**https://leetcode.com/problems/largest-magic-square/ */
//A k x k magic square is a k x k grid filled with integers such that every row sum, every column sum, and both diagonal sums are all equal. The integers in the magic square do not have to be distinct. Every 1 x 1 grid is trivially a magic square.
//Given an m x n integer grid, return the size (i.e., the side length k) of the largest magic square that can be found within this grid.
// 
//Example 1:
//Input: grid = [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]
//Output: 3
//Explanation: The largest magic square has a size of 3.
//Every row sum, column sum, and diagonal sum of this magic square is equal to 12.
//- Row sums: 5+1+6 = 5+4+3 = 2+7+3 = 12
//- Column sums: 5+5+2 = 1+4+7 = 6+3+3 = 12
//- Diagonal sums: 5+4+3 = 6+4+2 = 12
//Example 2:
//Input: grid = [[5,1,3,1],[9,3,3,1],[1,3,3,8]]
//Output: 2
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 50
//	1 <= grid[i][j] <= 106
/**
 * @param {number[][]} grid
 * @return {number}
 */
var largestMagicSquare = function(grid) {
    let m = grid.length;
    let n = grid[0].length;
    let rowSum = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));
    let colSum = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));
    let diaSum1 = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));
    let diaSum2 = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));
    let result = 1;
    for(let i = 1; i <= m; i++){
        for(let j = 1; j <= n; j++){
            rowSum[i][j] = rowSum[i][j - 1] + grid[i - 1][j - 1];
            colSum[i][j] = colSum[i - 1][j] + grid[i - 1][j - 1];
            diaSum1[i][j] = diaSum1[i - 1][j - 1] + grid[i - 1][j - 1];
            diaSum2[i][j] = diaSum2[i - 1][j + 1] + grid[i - 1][j - 1];
        }
    }
    for(let i = 1; i <= m; i++){
        for(let j = 1; j <= n; j++){
            for(let k = result + 1; k <= Math.min(m - i + 1, n - j + 1); k++){
                let row = rowSum[i][j + k - 1] - rowSum[i][j - 1];
                let col = colSum[i + k - 1][j] - colSum[i - 1][j];
                let dia1 = diaSum1[i + k - 1][j + k - 1] - diaSum1[i - 1][j - 1];
                let dia2 = diaSum2[i + k - 1][j - 1] - diaSum2[i - 1][j + k + 1];
                if(row === col && row === dia1 && row === dia2){
                    result = k;
                }
            }
        }
    }
    return result;

};