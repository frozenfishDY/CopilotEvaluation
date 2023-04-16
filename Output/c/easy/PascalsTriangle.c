/**https://leetcode.com/problems/pascals-triangle/ */
//Given an integer numRows, return the first numRows of Pascal's triangle.
//In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int **result = (int **)malloc(sizeof(int *) * numRows);
    *returnColumnSizes = (int *)malloc(sizeof(int) * numRows);
    for(int i = 0; i < numRows; i++){
        result[i] = (int *)malloc(sizeof(int) * (i + 1));
        (*returnColumnSizes)[i] = i + 1;
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i){
                result[i][j] = 1;
            }else{
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
            }
        }
    }
    *returnSize = numRows;
    return result;
    

}
    