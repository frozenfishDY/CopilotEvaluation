/**https://leetcode.com/problems/largest-1-bordered-square/ */
//Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't exist in the grid._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: grid = [[1,1,1],[1,0,1],[1,1,1]]_x000D_
//Output: 9_x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//Input: grid = [[1,1,0,0]]_x000D_
//Output: 1_x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	1 <= grid.length <= 100_x000D_
//	1 <= grid[0].length <= 100_x000D_
//	grid[i][j] is 0 or 1_x000D_


int largest1BorderedSquare(int** grid, int gridSize, int* gridColSize){
int m = gridSize, n = gridColSize[0];
    int **left = (int **)malloc(sizeof(int *) * m);
    for (int i = 0; i < m; ++i) {
        left[i] = (int *)malloc(sizeof(int) * n);
        memset(left[i], 0, sizeof(int) * n);
    }
    int **up = (int **)malloc(sizeof(int *) * m);
    for (int i = 0; i < m; ++i) {
        up[i] = (int *)malloc(sizeof(int) * n);
        memset(up[i], 0, sizeof(int) * n);
    }
    for (int i = 0; i < m; ++i) {
        left[i][0] = grid[i][0];
        for (int j = 1; j < n; ++j) {
            if (grid[i][j]) {
                left[i][j] = left[i][j - 1] + 1;
            }
        }
        up[i][0] = grid[i][0];
    }
    for (int j = 0; j < n; ++j) {
        for (int i = 1; i < m; ++i) {
            if (grid[i][j]) {
                up[i][j] = up[i - 1][j] + 1;
            }
        }
    }
    int res = 0;
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            int len = fmin(left[i][j], up[i][j]);
            while (len > res) {
                if (left[i - len + 1][j] >= len && up[i][j - len + 1] >= len) {
                    res = fmax(res, len);
                }
                --len;
            }
        }
    }
    return res * res;
}