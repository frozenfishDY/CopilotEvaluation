/**https://leetcode.com/problems/circle-and-rectangle-overlapping/ */
//You are given a circle represented as (radius, xCenter, yCenter) and an axis-aligned rectangle represented as (x1, y1, x2, y2), where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the rectangle.
//Return true if the circle and rectangle are overlapped otherwise return false. In other words, check if there is any point (xi, yi) that belongs to the circle and the rectangle at the same time.


bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2){
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

    