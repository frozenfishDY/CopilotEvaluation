/**https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/ */
//Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.
// 
//Example 1:
//Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
//Output: true
//Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.
//Example 2:
//Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
//Output: false
//Explanation: It is impossible to make mat equal to target by rotating mat.
//Example 3:
//Input: mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
//Output: true
//Explanation: We can rotate mat 90 degrees clockwise two times to make mat equal target.
// 
//Constraints:
//	n == mat.length == target.length
//	n == mat[i].length == target[i].length
//	1 <= n <= 10
//	mat[i][j] and target[i][j] are either 0 or 1.
bool findRotation(int** mat, int matSize, int* matColSize, int** target, int targetSize, int* targetColSize){
int i = 0, j = 0, k = 0, l = 0, max = 0, cnt = 0;
    int **p = (int **)calloc(matSize, sizeof(int *));
    for(i = 0; i < matSize; i++){
        p[i] = (int *)calloc(*matColSize, sizeof(int));
    }
    for(i = 0; i < matSize; i++){
        for(j = 0; j < *matColSize; j++){
            p[i][j] = mat[i][j];
        }
    }
    for(i = 0; i < 4; i++){
        for(j = 0; j < matSize; j++){
            for(k = 0; k < *matColSize; k++){
                if(p[j][k] != target[j][k]){
                    break;
                }
            }
            if(k != *matColSize){
                break;
            }
        }
        if(j == matSize){
            return true;
        }
        for(j = 0; j < matSize; j++){
            for(k = 0; k < *matColSize; k++){
                p[j][k] = mat[matSize - k - 1][j];
            }
        }
    }
    return false;
}