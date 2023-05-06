/**https://leetcode.com/problems/reshape-the-matrix/ */
//In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.
//You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.
//The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.
//If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes){
    int **result = (int **)malloc(sizeof(int *) * r);
    int *columnSize = (int *)malloc(sizeof(int) * r);
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    if(matSize * (*matColSize) != r * c){
        *returnSize = matSize;
        *returnColumnSizes = matColSize;
        return mat;
    }
    for(i = 0; i < r; i++){
        result[i] = (int *)malloc(sizeof(int) * c);
        columnSize[i] = c;
    }
    for(i = 0; i < matSize; i++){
        for(j = 0; j < *matColSize; j++){
            result[k][l] = mat[i][j];
            l++;
            if(l == c){
                l = 0;
                k++;
            }
        }
    }
    *returnSize = r;
    *returnColumnSizes = columnSize;
    return result;

}

    