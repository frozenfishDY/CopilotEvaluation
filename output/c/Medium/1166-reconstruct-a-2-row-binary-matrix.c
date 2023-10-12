/**https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/ */
//Given the following details of a matrix with n columns and 2 rows :
//	The matrix is a binary matrix, which means each element in the matrix can be 0 or 1.
//	The sum of elements of the 0-th(upper) row is given as upper.
//	The sum of elements of the 1-st(lower) row is given as lower.
//	The sum of elements in the i-th column(0-indexed) is colsum[i], where colsum is given as an integer array with length n.
//Your task is to reconstruct the matrix with upper, lower and colsum.
//Return it as a 2-D integer array.
//If there are more than one valid solution, any of them will be accepted.
//If no valid solution exists, return an empty 2-D array.
// 
//Example 1:
//Input: upper = 2, lower = 1, colsum = [1,1,1]
//Output: [[1,1,0],[0,0,1]]
//Explanation: [[1,0,1],[0,1,0]], and [[0,1,1],[1,0,0]] are also correct answers.
//Example 2:
//Input: upper = 2, lower = 3, colsum = [2,2,1,1]
//Output: []
//Example 3:
//Input: upper = 5, lower = 5, colsum = [2,1,2,0,1,0,1,2,0,1]
//Output: [[1,1,1,0,1,0,0,1,0,0],[1,0,1,0,0,0,1,1,0,1]]
// 
//Constraints:
//	1 <= colsum.length <= 10^5
//	0 <= upper, lower <= colsum.length
//	0 <= colsum[i] <= 2
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** reconstructMatrix(int upper, int lower, int* colsum, int colsumSize, int* returnSize, int** returnColumnSizes){
int **res = (int **)malloc(sizeof(int *) * 2);
    *returnSize = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int) * 2);
    (*returnColumnSizes)[0] = colsumSize;
    (*returnColumnSizes)[1] = colsumSize;
    res[0] = (int *)malloc(sizeof(int) * colsumSize);
    res[1] = (int *)malloc(sizeof(int) * colsumSize);
    memset(res[0], 0, sizeof(int) * colsumSize);
    memset(res[1], 0, sizeof(int) * colsumSize);
    for (int i = 0; i < colsumSize; ++i) {
        if (colsum[i] == 2) {
            res[0][i] = 1;
            res[1][i] = 1;
            ++*returnSize;
        }
    }
    for (int i = 0; i < colsumSize; ++i) {
        if (colsum[i] == 1) {
            if (upper > lower) {
                res[0][i] = 1;
                --upper;
            } else {
                res[1][i] = 1;
                --lower;
            }
            ++*returnSize;
        }
    }
    if (upper || lower) {
        *returnSize = 0;
        free(res[0]);
        free(res[1]);
        free(res);
        res = NULL;
    }
    return res;
}