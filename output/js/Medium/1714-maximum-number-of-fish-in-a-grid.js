/**https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/ */
//You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:
//	A land cell if grid[r][c] = 0, or
//	A water cell containing grid[r][c] fish, if grid[r][c] > 0.
//A fisher can start at any water cell (r, c) and can do the following operations any number of times:
//	Catch all the fish at cell (r, c), or
//	Move to any adjacent water cell.
//Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.
//An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.
// 
//Example 1:
//Input: grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
//Output: 7
//Explanation: The fisher can start at cell (1,3) and collect 3 fish, then move to cell (2,3) and collect 4 fish.
//Example 2:
//Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
//Output: 1
//Explanation: The fisher can start at cells (0,0) or (3,3) and collect a single fish. 
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 10
//	0 <= grid[i][j] <= 10
/**
 * @param {number[][]} grid
 * @return {number}
 */
var findMaxFish = function(grid) {
    let m = grid.length;
    let n = grid[0].length;
    let max = 0;
    let visited = new Array(m).fill().map(() => new Array(n).fill(false));
    let dirs = [[0,1],[0,-1],[1,0],[-1,0]];
    let dfs = (i, j) => {
        visited[i][j] = true;
        let sum = grid[i][j];
        for (let d of dirs) {
            let x = i + d[0];
            let y = j + d[1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > 0 && !visited[x][y]) {
                sum += dfs(x, y);
            }
        }
        return sum;
    }
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n;j++) {
            if (grid[i][j] > 0 && !visited[i][j]) {
                max = Math.max(max, dfs(i, j));
            }
        }
    }
    return max;
};