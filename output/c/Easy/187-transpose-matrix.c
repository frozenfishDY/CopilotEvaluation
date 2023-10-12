/**https://leetcode.com/problems/transpose-matrix/ */
//Given a 2D integer array matrix, return the transpose of matrix.
//The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.
// 
//Example 1:
//Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [[1,4,7],[2,5,8],[3,6,9]]
//Example 2:
//Input: matrix = [[1,2,3],[4,5,6]]
//Output: [[1,4],[2,5],[3,6]]
// 
//Constraints:
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m, n <= 1000
//	1 <= m * n <= 105
//	-109 <= matrix[i][j] <= 109
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes){
     *returnSize = matrixColSize[0];
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < *returnSize; i++){
        (*returnColumnSizes)[i] = matrixSize;
    }
    int** ret = (int**)malloc(sizeof(int*) * (*returnSize));
    for(int i = 0; i < *returnSize; i++){
        int* tmp = (int*)malloc(sizeof(int) * matrixSize);
        for(int j = 0; j < matrixSize; j++){
            tmp[j] = matrix[j][i];
        }
        ret[i] = tmp;
    }
    return ret;
}