/**https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/ */
//You are given an m x n integer matrix grid and an array queries of size k.
//Find an array answer of size k such that for each integer queres[i] you start in the top left cell of the matrix and repeat the following process:
//    If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
//    Otherwise, you do not get any points, and you end this process.
//After the process, answer[i] is the maximum number of points you can get. Note that for each query you are allowed to visit the same cell multiple times.
//Return the resulting array answer.


**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxPoints(int** grid, int gridSize, int* gridColSize, int* queries, int queriesSize, int* returnSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr[i] = 0;
    }
    int* arr2 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr2[i] = 0;
    }
    int* arr3 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr3[i] = 0;
    }
    int* arr4 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr4[i] = 0;
    }
    int* arr5 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr5[i] = 0;
    }
    int* arr6 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr6[i] = 0;
    }
    int* arr7 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr7[i] = 0;
    }
    int* arr8 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr8[i] = 0;
    }
    int* arr9 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr9[i] = 0;
    }
    int* arr10 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr10[i] = 0;
    }
    int* arr11 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr11[i] = 0;
    }
    int* arr12 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr12[i] = 0;
    }
    int* arr13 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr13[i] = 0;
    }
    int* arr14 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr

}

    