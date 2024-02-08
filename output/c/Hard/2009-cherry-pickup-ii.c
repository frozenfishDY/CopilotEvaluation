/**https://leetcode.com/problems/cherry-pickup-ii/ */
//You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.
//You have two robots that can collect cherries for you:
//Robot #1 is located at the top-left corner (0, 0), and
//Robot #2 is located at the top-right corner (0, cols - 1).
//Return the maximum number of cherries collection using both robots by following the rules below:
//From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
//When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
//When both robots stay in the same cell, only one takes the cherries.
//Both robots cannot move outside of the grid at any moment.
//Both robots should reach the bottom row in grid.


int cherryPickup(int** grid, int gridSize, int* gridColSize){
    int i,j;
    int** arr = (int**)malloc(sizeof(int*)*gridSize);
    for(i=0;i<gridSize;i++){
        arr[i] = (int*)malloc(sizeof(int)*gridColSize[0]);
    }
    for(i=0;i<gridSize;i++){
        for(j=0;j<gridColSize[0];j++){
            arr[i][j] = 0;
        }
    }
    for(i=0;i<gridSize;i++){
        for(j=0;j<gridColSize[0];j++){
            if(i == 0){
                if(j == 0){
                    arr[i][j] = grid[i][j];
                }
                else{
                    arr[i][j] = arr[i][j-1] + grid[i][j];
                }
            }
            else{
                if(j == 0){
                    arr[i][j] = arr[i-1][j] + grid[i][j];
                }
                else{
                    arr[i][j] = arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1] + grid[i][j];
                }
            }
        }
    }
    int** arr2 = (int**)malloc(sizeof(int*)*gridSize);
    for(i=0;i<gridSize;i++){
        arr2[i] = (int*)malloc(sizeof(int)*gridColSize[0]);
    }
    for(i=0;i<gridSize;i++){
        for(j=0;j<gridColSize[0];j++){
            arr2[i][j] = 0;
        }
    }
    for(i=0;i<gridSize;i++){
        for(j=0;j<gridColSize[0];j++){
            if(i == 0){
                if(j == gridColSize[0]-1){
                    arr2[i][j] = grid[i][j];
                }
                else{
                    arr2[i][j] = arr2[i][j+1] + grid[i][j];
                }
            }
            else{
                if(j == gridColSize[0]-1){
                    arr2[i][j] = arr2[i-1][j] + grid[i][j];
                }
                else{
                    arr2[i][j] = arr2[i-1][j] + arr2[i][j+1

}

    