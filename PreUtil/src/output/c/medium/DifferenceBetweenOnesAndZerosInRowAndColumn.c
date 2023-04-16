/**https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/ */
//You are given a 0-indexed m x n binary matrix grid.
//A 0-indexed m x n difference matrix diff is created with the following procedure:
//Let the number of ones in the ith row be onesRowi.
//Let the number of ones in the jth column be onesColj.
//Let the number of zeros in the ith row be zerosRowi.
//Let the number of zeros in the jth column be zerosColj.
//diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj
//Return the difference matrix diff.


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** onesMinusZeros(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes){
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

    