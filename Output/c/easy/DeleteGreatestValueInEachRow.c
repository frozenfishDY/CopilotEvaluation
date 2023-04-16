/**https://leetcode.com/problems/delete-greatest-value-in-each-row/ */
//You are given an m x n matrix grid consisting of positive integers.
//Perform the following operation until grid becomes empty:
//Delete the element with the greatest value from each row. If multiple such elements exist, delete any of them.
//Add the maximum of deleted elements to the answer.
//Note that the number of columns decreases by one after each operation.
//Return the answer after performing the operations described above.


int deleteGreatestValue(int** grid, int gridSize, int* gridColSize){
    int i = 0;
    int j = 0;
    int k = 0;
    int max = 0;
    int result = 0;
    int temp = 0;
    int flag = 0;
    int *arr = (int *)malloc(sizeof(int) * gridSize);
    for(i = 0; i < gridSize; i++){
        max = grid[i][0];
        for(j = 0; j < gridColSize[i]; j++){
            if(grid[i][j] > max){
                max = grid[i][j];
            }
        }
        arr[i] = max;
    }
    for(i = 0; i < gridSize; i++){
        for(j = 0; j < gridColSize[i]; j++){
            if(grid[i][j] == arr[i]){
                for(k = j; k < gridColSize[i] - 1; k++){
                    grid[i][k] = grid[i][k + 1];
                }
                gridColSize[i]--;
                break;
            }
        }
    }
    for(i = 0; i < gridSize; i++){
        if(gridColSize[i] == 0){
            flag = 1;
        }
    }
    if(flag == 1){
        return 0;
    }
    for(i = 0; i < gridSize; i++){
        max = grid[i][0];
        for(j = 0; j < gridColSize[i]; j++){
            if(grid[i][j] > max){
                max = grid[i][j];
            }
        }
        result += max;
    }
    return result;

}

    