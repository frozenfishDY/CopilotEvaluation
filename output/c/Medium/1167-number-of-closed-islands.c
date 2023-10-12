/**https://leetcode.com/problems/number-of-closed-islands/ */
//Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.
//Return the number of closed islands.
// 
//Example 1:
//Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
//Output: 2
//Explanation: 
//Islands in gray are closed because they are completely surrounded by water (group of 1s).
//Example 2:
//Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
//Output: 1
//Example 3:
//Input: grid = [[1,1,1,1,1,1,1],
//               [1,0,0,0,0,0,1],
//               [1,0,1,1,1,0,1],
//               [1,0,1,0,1,0,1],
//               [1,0,1,1,1,0,1],
//               [1,0,0,0,0,0,1],
//               [1,1,1,1,1,1,1]]
//Output: 2
// 
//Constraints:
//	1 <= grid.length, grid[0].length <= 100
//	0 <= grid[i][j] <=1
int closedIsland(int** grid, int gridSize, int* gridColSize){
int m = gridSize, n = gridColSize[0];
    int **visited = (int **)malloc(sizeof(int *) * m);
    for (int i = 0; i < m; ++i) {
        visited[i] = (int *)malloc(sizeof(int) * n);
        memset(visited[i], 0, sizeof(int) * n);
    }
    int res = 0;
    for (int i = 0; i < m; ++i) {
        if (grid[i][0] == 0 && !visited[i][0]) {
            dfs(grid, visited, m, n, i, 0);
        }
        if (grid[i][n - 1] == 0 && !visited[i][n - 1]) {
            dfs(grid, visited, m, n, i, n - 1);
        }
    }
    for (int j = 0; j < n; ++j) {
        if (grid[0][j] == 0 && !visited[0][j]) {
            dfs(grid, visited, m, n, 0, j);
        }
        if (grid[m - 1][j] == 0 && !visited[m - 1][j]) {
            dfs(grid, visited, m, n, m - 1, j);
        }
    }
    for (int i = 1; i < m - 1; ++i) {
        for (int j = 1; j < n - 1; ++j) {
            if (grid[i][j] == 0 && !visited[i][j]) {
                dfs(grid, visited, m, n, i, j);
                ++res;
            }
        }
    }
    return res;
}
void dfs(int **grid, int **visited, int m, int n, int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] == 1) {
        return;
    }
    visited[i][j] = 1;
    dfs(grid, visited, m, n, i - 1, j);
    dfs(grid, visited, m, n, i + 1, j);
    dfs(grid, visited, m, n, i, j - 1);

}