/**https://leetcode.com/problems/minimum-falling-path-sum/ */
//Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
//A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).


int minFallingPathSum(int** matrix, int matrixSize, int* matrixColSize){
    int** dp = (int**)malloc(sizeof(int*) * matrixSize);
    for(int i = 0; i < matrixSize; i++){
        dp[i] = (int*)malloc(sizeof(int) * matrixColSize[i]);
    }
    for(int i = 0; i < matrixColSize[0]; i++){
        dp[0][i] = matrix[0][i];
    }
    for(int i = 1; i < matrixSize; i++){
        for(int j = 0; j < matrixColSize[i]; j++){
            int min = dp[i - 1][j];
            if(j > 0 && dp[i - 1][j - 1] < min){
                min = dp[i - 1][j - 1];
            }
            if(j < matrixColSize[i] - 1 && dp[i - 1][j + 1] < min){
                min = dp[i - 1][j + 1];
            }
            dp[i][j] = min + matrix[i][j];
        }
    }
    int min = dp[matrixSize - 1][0];
    for(int i = 1; i < matrixColSize[matrixSize - 1]; i++){
        if(dp[matrixSize - 1][i] < min){
            min = dp[matrixSize - 1][i];
        }
    }
    return min;

}

    