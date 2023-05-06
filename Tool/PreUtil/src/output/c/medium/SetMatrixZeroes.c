/**https://leetcode.com/problems/set-matrix-zeroes/ */
//Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
//You must do it in place.


void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int row[matrixSize];
    int col[*matrixColSize];
    for(int i = 0; i < matrixSize; i++){
        row[i] = 0;
    }
    for(int i = 0; i < *matrixColSize; i++){
        col[i] = 0;
    }
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < *matrixColSize; j++){
            if(matrix[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < *matrixColSize; j++){
            if(row[i] == 1 || col[j] == 1){
                matrix[i][j] = 0;
            }
        }
    }

}

    