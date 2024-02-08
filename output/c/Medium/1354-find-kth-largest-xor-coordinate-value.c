/**https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/ */
//You are given a 2D matrix of size m x n, consisting of non-negative integers. You are also given an integer k.
//The value of coordinate (a, b) of the matrix is the XOR of all matrix[i][j] where 0 <= i <= a < m and 0 <= j <= b < n (0-indexed).
//Find the kth largest value (1-indexed) of all the coordinates of matrix.


int kthLargestValue(int** matrix, 
int matrixSize, int* matrixColSize, int k){
    int i, j, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int* arr = (int*)malloc(sizeof(int) * (matrixSize * matrixColSize[0]));
    for(i = 0; i < (matrixSize * matrixColSize[0]); i++){arr[i] = 0;}
    int* arr2 = (int*)malloc(sizeof(int) * (matrixSize * matrixColSize[0]));
    for(i = 0; i < (matrixSize * matrixColSize[0]); i++){arr2[i] = 0;}
    int* arr3 = (int*)malloc(sizeof(int) * (matrixSize * matrixColSize[0]));
    for(i = 0; i < (matrixSize * matrixColSize[0]); i++){arr3[i] = 0;}
    int* arr4 = (int*)malloc(sizeof(int) * (matrixSize * matrixColSize[0]));
    for(i = 0; i < (matrixSize * matrixColSize[0]); i++){arr4[i] = 0;}
    int* arr5 = (int*)malloc(sizeof(int) * (matrixSize * matrixColSize[0]));
    for(i = 0; i < (matrixSize * matrixColSize[0]); i++){arr5[i] = 0;}
    int* arr6 = (int*)malloc(sizeof(int) * (matrixSize * matrixColSize[0]));
    for(i = 0; i < (matrixSize * matrixColSize[0]); i++){arr6[i] = 0;}
    int* arr7 = (int*)malloc(sizeof(int) * (matrixSize * matrixColSize[0]));
    for(i = 0; i < (matrixSize * matrixColSize[0]); i++){arr7[i] = 0;}
    int* arr8 = (int*)malloc(sizeof(int) * (matrixSize * matrixColSize[0]));
    for(i = 0; i < (matrixSize * matrixColSize[0]); i++){arr8[i] = 0;}
    int* arr9 = (int*)malloc(sizeof(int) * (matrixSize * matrixColSize [0]));
    for(i = 0; i < (matrixSize * matrixColSize[0]); i++){arr9[i] = 0;}
    int* arr10 = (int*)malloc(sizeof(int) * (matrixSize * matrixColSize[0]));
    for(i = 0; i < (matrixSize * matrixColSize[0]); i++){arr10[i] = 0;}
}

    