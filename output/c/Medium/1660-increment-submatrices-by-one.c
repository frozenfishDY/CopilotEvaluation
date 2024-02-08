/**https://leetcode.com/problems/increment-submatrices-by-one/ */
//You are given a positive integer n, indicating that we initially have an n x n 0-indexed integer matrix mat filled with zeroes.
//You are also given a 2D integer array query. For each query[i] = [row1i, col1i, row2i, col2i], you should do the following operation:
//Add 1 to every element in the submatrix with the top left corner (row1i, col1i) and the bottom right corner (row2i, col2i). That is, add 1 to mat[x][y] for for all row1i <= x <= row2i and col1i <= y <= col2i.
//Return the matrix mat after performing every query.


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** rangeAddQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize, int** returnColumnSizes){
    int** result = (int**)malloc(sizeof(int*) * n);
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        result[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
        for(int j = 0; j < n; j++){
            result[i][j] = 0;
        }
    }
    for(int i = 0; i < queriesSize; i++){
        for(int j = queries[i][0]; j <= queries[i][2]; j++){
            for(int k = queries[i][1]; k <= queries[i][3]; k++){
                result[j][k]++;
            }
        }
    }
    *returnSize = n;
    return result;


}

    