/**https://leetcode.com/problems/max-increase-to-keep-city-skyline/ */
//There is a city composed of n x n blocks, where each block contains a single building shaped like a vertical square prism. You are given a 0-indexed n x n integer matrix grid where grid[r][c] represents the height of the building located in the block at row r and column c.
//A city's skyline is the the outer contour formed by all the building when viewing the side of the city from a distance. The skyline from each cardinal direction north, east, south, and west may be different.
//We are allowed to increase the height of any number of buildings by any amount (the amount can be different per building). The height of a 0-height building can also be increased. However, increasing the height of a building should not affect the city's skyline from any cardinal direction.
//Return the maximum total sum that the height of the buildings can be increased by without changing the city's skyline from any cardinal direction.


int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize){
    int* rowMax = (int*)malloc(sizeof(int) * gridSize);
    int* colMax = (int*)malloc(sizeof(int) * *gridColSize);
    for(int i = 0; i < gridSize; i++){
        rowMax[i] = 0;
        for(int j = 0; j < *gridColSize; j++){
            rowMax[i] = fmax(rowMax[i], grid[i][j]);
        }
    }
    for(int i = 0; i < *gridColSize; i++){
        colMax[i] = 0;
        for(int j = 0; j < gridSize; j++){
            colMax[i] = fmax(colMax[i], grid[j][i]);
        }
    }
    int sum = 0;
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < *gridColSize; j++){
            sum += fmin(rowMax[i], colMax[j]) - grid[i][j];
        }
    }
    return sum;

}

    