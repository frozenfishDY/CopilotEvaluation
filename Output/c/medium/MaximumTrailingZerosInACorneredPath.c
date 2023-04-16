/**https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path/ */
//You are given a 2D integer array grid of size m x n, where each cell contains a positive integer.
//A cornered path is defined as a set of adjacent cells with at most one turn. More specifically, the path should exclusively move either horizontally or vertically up to the turn (if there is one), without returning to a previously visited cell. After the turn, the path will then move exclusively in the alternate direction: move vertically if it moved horizontally, and vice versa, also without returning to a previously visited cell.
//The product of a path is defined as the product of all the values in the path.
//Return the maximum number of trailing zeros in the product of a cornered path found in grid.
//Note:
//Horizontal movement means moving in either the left or right direction.
//Vertical movement means moving in either the up or down direction.


int maxTrailingZeros(int** grid, int gridSize, int* gridColSize){
    int i, j, k, l, m, n, max = 0, count = 0, temp = 0;
    int arr[100000] = {0};
    for(i = 0; i < gridSize; i++){
        for(j = 0; j < gridColSize[i]; j++){
            temp = grid[i][j];
            while(temp % 5 == 0){
                temp /= 5;
                count++;
            }
            arr[grid[i][j]] = count;
            count = 0;
        }
    }
    for(i = 0; i < gridSize; i++){
        for(j = 0; j < gridColSize[i]; j++){
            for(k = i; k < gridSize; k++){
                for(l = j; l < gridColSize[k]; l++){
                    for(m = i; m <= k; m++){
                        for(n = j; n <= l; n++){
                            count += arr[grid[m][n]];
                        }
                    }
                    if(count > max){
                        max = count;
                    }
                    count = 0;
                }
            }
        }
    }
    return max;

}

    