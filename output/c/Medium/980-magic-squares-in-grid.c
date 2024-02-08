/**https://leetcode.com/problems/magic-squares-in-grid/ */
//A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.
//Given a row x col grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).


int numMagicSquaresInside(int** grid, int gridSize, int* gridColSize){
    int count = 0;
    for(int i = 0; i < gridSize - 2; i++){
        for(int j = 0; j < gridColSize[0] - 2; j++){
            if(grid[i + 1][j + 1] != 5){
                continue;
            }
            if(grid[i][j] + grid[i][j + 1] + grid[i][j + 2] != 15){
                continue;
            }
            if(grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2] != 15){
                continue;
            }
            if(grid[i][j] + grid[i + 1][j] + grid[i + 2][j] != 15){
                continue;
            }
            if(grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2] != 15){
                continue;
            }
            if(grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] != 15){
                continue;
            }
            if(grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] != 15){
                continue;
            }
            int* hash = (int*)malloc(sizeof(int) * 10);
            for(int k = 0; k < 10; k++){
                hash[k] = 0;
            }
            for(int k = 0; k < 3; k++){
                for(int l = 0; l < 3; l++){
                    if(grid[i + k][j + l] < 1 || grid[i + k][j + l] > 9){
                        continue;
                    }
                    hash[grid[i + k][j + l]]++;
                }
            }
            int flag = 1;
            for(int k = 1; k < 10; k++){
                if(hash[k] != 1){
                    flag = 0;
                    break;
                }
            }
            if(flag == 1){
                count++;
            }
        }
    }
    return count;

}

    