/**https://leetcode.com/problems/simplified-fractions/ */
//Given an integer n, return a list of all simplified fractions between 0 and 1 (exclusive) such that the denominator is less-than-or-equal-to n. You can return the answer in any order.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** simplifiedFractions(int n, int* returnSize){
    int i, j, k, l, m, n, count = 0, **result;
    int *row, *col;
    row = (int*)malloc(gridSize * sizeof(int));
    col = (int*)malloc(gridColSize[0] * sizeof(int));
    for(i = 0; i < gridSize; i++){
        row[i] = 0;
        for(j = 0; j < gridColSize[0]; j++){
            if(grid[i][j] == 1){
                row[i]++;
            }
        }
    }
    for(i = 0; i < gridColSize[0]; i++){
        col[i] = 0;
        for(j = 0; j < gridSize; j++){
            if(grid[j][i] == 1){
                col[i]++;
            }
        }
    }
    result = (int**)malloc(gridSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(gridSize * sizeof(int));
    for(i = 0; i < gridSize; i++){
        result[i] = (int*)malloc(gridColSize[0] * sizeof(int));
        (*returnColumnSizes)[i] = gridColSize[0];
        for(j = 0; j < gridColSize[0]; j++){
            result[i][j] = row[i] + col[j];
            if(grid[i][j] == 1){
                result[i][j] -= 2;
            }
        }
    }
    *returnSize = gridSize;
    return result;

}

    