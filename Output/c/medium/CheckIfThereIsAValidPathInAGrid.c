/**https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/ */
//You are given an m x n grid. Each cell of grid represents a street. The street of grid[i][j] can be:
//1 which means a street connecting the left cell and the right cell.
//2 which means a street connecting the upper cell and the lower cell.
//3 which means a street connecting the left cell and the lower cell.
//4 which means a street connecting the right cell and the lower cell.
//5 which means a street connecting the left cell and the upper cell.
//6 which means a street connecting the right cell and the upper cell.
//You will initially start at the street of the upper-left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1). The path should only follow the streets.
//Notice that you are not allowed to change any street.
//Return true if there is a valid path in the grid or false otherwise.


bool hasValidPath(int** grid, int gridSize, int* gridColSize){
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

    