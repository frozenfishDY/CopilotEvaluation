/**https://leetcode.com/problems/score-after-flipping-matrix/ */
//You are given an m x n binary matrix grid.
//A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).
//Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.
//Return the highest possible score after making any number of moves (including zero moves).


int matrixScore(int** grid, int gridSize, int* gridColSize){
    int m = gridSize;
    int n = gridColSize[0];
    int* row = (int*)malloc(sizeof(int) * m);
    int* col = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < m; i++){
        row[i] = 0;
    }
    for(int i = 0; i < n; i++){
        col[i] = 0;
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1){
                row[i]++;
                col[j]++;
            }
        }
    }
    int count = 0;
    for(int i = 0; i < m; i++){
        if(row[i] < n / 2){
            count += n - row[i];
        }
        else{
            count += row[i];
        }
    }
    for(int i = 0; i < n; i++){
        if(col[i] < m / 2){
            count += m - col[i];
        }
        else{
            count += col[i];
        }
    }
    return count;

}

    