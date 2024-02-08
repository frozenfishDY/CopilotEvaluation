/**https://leetcode.com/problems/largest-submatrix-with-rearrangements/ */
//You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.
//Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.


int largestSubmatrix(int** matrix, int matrixSize, int* matrixColSize){
    int len = matrixColSize[0];
    int count = 0;
    int max = 0;
    for(int i = 0; i < len; i++){
        for(int j = 0; j < matrixSize; j++){
            if(matrix[j][i] == 1){
                count++;
            }else{
                count = 0;
            }
            matrix[j][i] = count;
        }
    }
    for(int i = 0; i < matrixSize; i++){
        qsort(matrix[i], len, sizeof(int), cmpfunc);
        for(int j = 0; j < len; j++){
            if(matrix[i][j] * (len - j) > max){
                max = matrix[i][j] * (len - j);
            }
        }
    }
    return max;


}

    