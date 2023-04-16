/**https://leetcode.com/problems/grid-illumination/ */
//There is a 2D grid of size n x n where each cell of this grid has a lamp that is initially turned off.
//You are given a 2D array of lamp positions lamps, where lamps[i] = [rowi, coli] indicates that the lamp at grid[rowi][coli] is turned on. Even if the same lamp is listed more than once, it is turned on.
//When a lamp is turned on, it illuminates its cell and all other cells in the same row, column, or diagonal.
//You are also given another 2D array queries, where queries[j] = [rowj, colj]. For the jth query, determine whether grid[rowj][colj] is illuminated or not. After answering the jth query, turn off the lamp at grid[rowj][colj] and its 8 adjacent lamps if they exist. A lamp is adjacent if its cell shares either a side or corner with grid[rowj][colj].
//Return an array of integers ans, where ans[j] should be 1 if the cell in the jth query was illuminated, or 0 if the lamp was not.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* gridIllumination(int n, int** lamps, int lampsSize, int* lampsColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    int* ans = (int*)malloc(sizeof(int)*queriesSize);
    *returnSize = queriesSize;
    int i,j;
    int** grid = (int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        grid[i] = (int*)malloc(sizeof(int)*n);
        for(j=0;j<n;j++){
            grid[i][j] = 0;
        }
    }
    int** row = (int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        row[i] = (int*)malloc(sizeof(int)*n);
        for(j=0;j<n;j++){
            row[i][j] = 0;
        }
    }
    int** col = (int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        col[i] = (int*)malloc(sizeof(int)*n);
        for(j=0;j<n;j++){
            col[i][j] = 0;
        }
    }
    int** diag1 = (int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        diag1[i] = (int*)malloc(sizeof(int)*n);
        for(j=0;j<n;j++){
            diag1[i][j] = 0;
        }
    }
    int** diag2 = (int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        diag2[i] = (int*)malloc(sizeof(int)*n);
        for(j=0;j<n;j++){
            diag2[i][j] = 0;
        }
    }
    for(i=0;i<lampsSize;i++){
        grid[lamps[i][0]][lamps[i][1]] = 1;
        row[lamps[i][0]][lamps[i][1]] = 1;
        col[lamps[i][0]][lamps[i][1]] = 1;
        diag1[lamps[i][0]][lamps[i][1]] = 1;
        diag2[lamps[i][0]][lamps[i][1]] = 1;
    }
    for(i=0;i<queriesSize;i++){
        if(grid[queries[i][0]][queries[i][1]] == 1){
            ans[i] = 1;
            grid[queries[i][0]][queries[i][1]] = 0;
            row[queries[i][0]][queries[i][1]] = 0;
            col[queries[i][0]][queries[i][1]] = 0;
            diag1[queries[i][0]][queries[i][1]] = 0;
            diag2[queries[i][0]][queries[i][1]] = 0;
            if(queries[i][0] - 1 >= 0){
                grid[queries[i][0] - 1][queries[i][1]] = 0;
                row[queries[i][0] - 1][queries[i][1]] = 0;
                if(queries[i][1] - 1 >= 0){
                    col[queries[i][0] - 1][queries[i][1] - 1] = 0;
                    diag1[queries[i][0] - 1][queries[i][1] - 1] = 0;
                }
                if(queries[i][1] + 1 < n){
                    col[queries[i][0] - 1][queries[i][1] + 1] = 0;
                    diag2[queries[i][0] - 1][queries[i][1] + 1] = 0;
                }
            }
            if(queries[i][0] + 1 < n){
                grid[queries[i][0] + 1][queries[i][1]] = 0;
                row[queries[i][0] + 1][queries[i][1]] = 0;
                if(queries[i][1] - 1 >= 0){
                    col[queries[i][0] + 1][queries[i][1] - 1] = 0;
                    diag2[queries[i][0] + 1][queries[i][1] - 1] = 0;
                }
                if(queries[i][1] + 1 < n){
                    col[queries[i][0] + 1][queries[i][1] + 1] = 0;
                    diag1[queries[i][0] + 1][queries[i][1] + 1] = 0;
                }
            }
            if(queries[i][1] - 1 >= 0){
                grid[queries[i][0]][queries[i][1] - 1] = 0;
                col[queries[i][0]][queries[i][1] - 1] = 0;
            }
            if(queries[i][1] + 1 < n){
                grid[queries[i][0]][queries[i][1] + 1] = 0;
                col[queries[i][0]][queries[i][1] + 1] = 0;
            }

            

}

    