/**https://leetcode.com/problems/01-matrix/ */
//Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
//The distance between two adjacent cells is 1.
// 
//Example 1:
//Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
//Output: [[0,0,0],[0,1,0],[0,0,0]]
//Example 2:
//Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
//Output: [[0,0,0],[0,1,0],[1,2,1]]
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 104
//	1 <= m * n <= 104
//	mat[i][j] is either 0 or 1.
//	There is at least one 0 in mat.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes){
int row = matSize, col = matColSize[0];
	int** res = (int**)malloc(sizeof(int*) * row);
	*returnColumnSizes = (int*)malloc(sizeof(int) * row);
	int i = 0, j = 0;
	for (i = 0; i < row; i++) {
		res[i] = (int*)malloc(sizeof(int) * col);
		(*returnColumnSizes)[i] = col;
		for (j = 0; j < col; j++) {
			if (mat[i][j] == 0) {
				res[i][j] = 0;
			} else {
				res[i][j] = 10000;
			}
		}
	}
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (i - 1 >= 0) {
				res[i][j] = fmin(res[i][j], res[i - 1][j] + 1);
			}
			if (j - 1 >= 0) {
				res[i][j] = fmin(res[i][j], res[i][j - 1] + 1);
			}
		}
	}
	for (i = row - 1; i >= 0; i--) {
		for (j = col - 1; j >= 0; j--) {
			if (i + 1 < row) {
				res[i][j] = fmin(res[i][j], res[i + 1][j] + 1);
			}
			if (j + 1 < col) {
				res[i][j] = fmin(res[i][j], res[i][j + 1] + 1);
			}
		}
	}
	return res;
}