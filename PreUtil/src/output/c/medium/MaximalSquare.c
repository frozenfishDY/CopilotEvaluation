/**https://leetcode.com/problems/maximal-square/ */
//Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.


int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    int max = 0;
    int** result = (int**)malloc(sizeof(int*) * matrixSize);
    for(int i = 0; i < matrixSize; i++){
        result[i] = (int*)malloc(sizeof(int) * matrixColSize[0]);
        for(int j = 0; j < matrixColSize[0]; j++){
            result[i][j] = 0;
        }
    }
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < matrixColSize[0]; j++){
            if(matrix[i][j] == '1'){
                if(i == 0 || j == 0){
                    result[i][j] = 1;
                }else{
                    result[i][j] = 1 + fmin(fmin(result[i - 1][j], result[i][j - 1]), result[i - 1][j - 1]);
                }
                if(result[i][j] > max){
                    max = result[i][j];
                }
            }
        }
    }
    return max * max;

}

    