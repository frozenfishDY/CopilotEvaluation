/**https://leetcode.com/problems/path-with-maximum-gold/ */
//In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.
//Return the maximum amount of gold you can collect under the conditions:
//	Every time you are located in a cell you will collect all the gold in that cell.
//	From your position, you can walk one step to the left, right, up, or down.
//	You can't visit the same cell more than once.
//	Never visit a cell with 0 gold.
//	You can start and stop collecting gold from any position in the grid that has some gold.
// 
//Example 1:
//Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
//Output: 24
//Explanation:
//[[0,6,0],
// [5,8,7],
// [0,9,0]]
//Path to get the maximum gold, 9 -> 8 -> 7.
//Example 2:
//Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
//Output: 28
//Explanation:
//[[1,0,7],
// [2,0,6],
// [3,4,5],
// [0,3,0],
// [9,0,20]]
//Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 15
//	0 <= grid[i][j] <= 100
//	There are at most 25 cells containing gold.
void dfs(int **grid, int **visited, int m, int n, int i, int j, int sum, int *res) {
        if (i < 0 || i >= m || j < 0 || j >= n || !grid[i][j] || visited[i][j]) {
            return;
        }
        sum += grid[i][j];
        if (sum > *res) {
            *res = sum;
        }
        visited[i][j] = 1;
        dfs(grid, visited, m, n, i - 1, j, sum, res);
        dfs(grid, visited, m, n, i + 1, j, sum, res);
        dfs(grid, visited, m, n, i, j - 1, sum, res);
        dfs(grid, visited, m, n, i, j + 1, sum, res);
        visited[i][j] = 0;
    }
int getMaximumGold(int** grid, int gridSize, int* gridColSize){
int m = gridSize, n = gridColSize[0];
    int res = 0;
    int **visited = (int **)malloc(sizeof(int *) * m);
    for (int i = 0; i < m; ++i) {
        visited[i] = (int *)malloc(sizeof(int) * n);
        memset(visited[i], 0, sizeof(int) * n);
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j){
            if (grid[i][j]) {
                dfs(grid, visited, m, n, i, j, 0, &res);
            }
        }
    }
    return res;
}