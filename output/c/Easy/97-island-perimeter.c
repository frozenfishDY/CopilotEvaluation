/**https://leetcode.com/problems/island-perimeter/ */
//You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.
//Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
//The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.


int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    int i = 0;
    int j = 0;
    int count = 0;
    for(i = 0; i < gridSize; i++){
        for(j = 0; j < gridColSize[i]; j++){
            if(grid[i][j] == 1){
                if(i == 0){
                    count++;
                }
                if(i == gridSize - 1){
                    count++;
                }
                if(j == 0){
                    count++;
                }
                if(j == gridColSize[i] - 1){
                    count++;
                }
                if(i > 0 && grid[i - 1][j] == 0){
                    count++;
                }
                if(i < gridSize - 1 && grid[i + 1][j] == 0){
                    count++;
                }
                if(j > 0 && grid[i][j - 1] == 0){
                    count++;
                }
                if(j < gridColSize[i] - 1 && grid[i][j + 1] == 0){
                    count++;
                }
            }
        }
    }
    return count;

}

    