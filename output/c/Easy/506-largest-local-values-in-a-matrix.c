/**https://leetcode.com/problems/largest-local-values-in-a-matrix/ */
//You are given an n x n integer matrix grid.
//Generate an integer matrix maxLocal of size (n - 2) x (n - 2) such that:
//	maxLocal[i][j] is equal to the largest value of the 3 x 3 matrix in grid centered around row i + 1 and column j + 1.
//In other words, we want to find the largest value in every contiguous 3 x 3 matrix in grid.
//Return the generated matrix.
// 
//Example 1:
//Input: grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
//Output: [[9,9],[8,6]]
//Explanation: The diagram above shows the original matrix and the generated matrix.
//Notice that each value in the generated matrix corresponds to the largest value of a contiguous 3 x 3 matrix in grid.
//Example 2:
//Input: grid = [[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]
//Output: [[2,2,2],[2,2,2],[2,2,2]]
//Explanation: Notice that the 2 is contained within every contiguous 3 x 3 matrix in grid.
// 
//Constraints:
//	n == grid.length == grid[i].length
//	3 <= n <= 100
//	1 <= grid[i][j] <= 100
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** largestLocal(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes){
int **res = NULL;
    int resSize = 0;
    int i = 0, j = 0, k = 0;
    int **hash = (int**)calloc(gridSize - 2, sizeof(int*));
    for (i = 0; i < gridSize - 2; i++) {
        hash[i] = (int*)calloc(gridColSize[i] - 2, sizeof(int));
        for (j = 0; j < gridColSize[i] - 2; j++) {
            hash[i][j] = grid[i + 1][j + 1];
            for (k = -1; k <= 1; k++) {
                if (grid[i][j + 1 + k] > hash[i][j]) {
                    hash[i][j] = grid[i][j + 1 + k];
                }
                if (grid[i + 1][j + k] > hash[i][j]) {
                    hash[i][j] = grid[i + 1][j + k];
                }
                if (grid[i + 2][j + 1 + k] > hash[i][j]) {
                    hash[i][j] = grid[i + 2][j + 1 + k];
                }
            }
        }
    }
    res = (int**)calloc(gridSize - 2, sizeof(int*));
    *returnColumnSizes = (int*)calloc(gridSize - 2, sizeof(int));
    for (i = 0; i < gridSize - 2; i++) {
        res[i] = (int*)calloc(gridColSize[i] - 2, sizeof(int));
        (*returnColumnSizes)[i] = gridColSize[i] - 2;
        for (j = 0; j < gridColSize[i] - 2; j++) {
            res[i][j] = hash[i][j];
        }
    }
    *returnSize = gridSize - 2;
    return res;
}