/**https://leetcode.com/problems/rotting-oranges/ */
//You are given an m x n grid where each cell can have one of three values:
//0 representing an empty cell,
//1 representing a fresh orange, or
//2 representing a rotten orange.
//Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
//Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.


int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int result = 0;
    int fresh = 0;
    int rotten = 0;
    int* rottenX = (int*)malloc(sizeof(int) * gridSize * (*gridColSize));
    int* rottenY = (int*)malloc(sizeof(int) * gridSize * (*gridColSize));
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < *gridColSize; j++){
            if(grid[i][j] == 1){
                fresh++;
            }
            else if(grid[i][j] == 2){
                rottenX[rotten] = i;
                rottenY[rotten] = j;
                rotten++;
            }
        }
    }
    while(fresh > 0){
        int newRotten = 0;
        int* newRottenX = (int*)malloc(sizeof(int) * gridSize * (*gridColSize));
        int* newRottenY = (int*)malloc(sizeof(int) * gridSize * (*gridColSize));
        for(int i = 0; i < rotten; i++){
            if(rottenX[i] > 0 && grid[rottenX[i] - 1][rottenY[i]] == 1){
                grid[rottenX[i] - 1][rottenY[i]] = 2;
                newRottenX[newRotten] = rottenX[i] - 1;
                newRottenY[newRotten] = rottenY[i];
                newRotten++;
                fresh--;
            }
            if(rottenX[i] < gridSize - 1 && grid[rottenX[i] + 1][rottenY[i]] == 1){
                grid[rottenX[i] + 1][rottenY[i]] = 2;
                newRottenX[newRotten] = rottenX[i] + 1;
                newRottenY[newRotten] = rottenY[i];
                newRotten++;
                fresh--;
            }
            if(rottenY[i] > 0 && grid[rottenX[i]][rottenY[i] - 1] == 1){
                grid[rottenX[i]][rottenY[i] - 1] = 2;
                newRottenX[newRotten] = rottenX[i];
                newRottenY[newRotten] = rottenY[i] - 1;
                newRotten++;
                fresh--;
                

}

    