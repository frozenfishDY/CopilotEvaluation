/**https://leetcode.com/problems/sort-the-matrix-diagonally/ */
//A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the matrix diagonal starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].
//Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** diagonalSort(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes){
    int** result = malloc(matSize * sizeof(int*));
    for(int i = 0; i < matSize; i++){
        result[i] = malloc(matColSize[i] * sizeof(int));
        memcpy(result[i], mat[i], matColSize[i] * sizeof(int));
    }
    for(int i = 0; i < matSize; i++){
        int* queue = malloc(matSize * matColSize[i] * sizeof(int));
        int queueSize = 0;
        int row = i;
        int col = 0;
        while(row < matSize && col < matColSize[i]){
            queue[queueSize++] = mat[row++][col++];
        }
        qsort(queue, queueSize, sizeof(int), cmp);
        row = i;
        col = 0;
        int queueIndex = 0;
        while(row < matSize && col < matColSize[i]){
            result[row++][col++] = queue[queueIndex++];
        }
        free(queue);
    }
    for(int i = 1; i < matColSize[0]; i++){
        int* queue = malloc(matSize * matColSize[i] * sizeof(int));
        int queueSize = 0;
        int row = 0;
        int col = i;
        while(row < matSize && col < matColSize[i]){
            queue[queueSize++] = mat[row++][col++];
        }
        qsort(queue, queueSize, sizeof(int), cmp);
        row = 0;
        col = i;
        int queueIndex = 0;
        while(row < matSize && col < matColSize[i]){
            result[row++][col++] = queue[queueIndex++];
        }
        free(queue);
    }
    *returnSize = matSize;
    *returnColumnSizes = matColSize;
    return result;

}

    