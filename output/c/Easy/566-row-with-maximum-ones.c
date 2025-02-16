/**https://leetcode.com/problems/row-with-maximum-ones/ */
//Given a m x n binary matrix mat, find the 0-indexed position of the row that contains the maximum count of ones, and the number of ones in that row.
//In case there are multiple rows that have the maximum count of ones, the row with the smallest row number should be selected.
//Return an array containing the index of the row, and the number of ones in it.
// 
//Example 1:
//Input: mat = [[0,1],[1,0]]
//Output: [0,1]
//Explanation: Both rows have the same number of 1's. So we return the index of the smaller row, 0, and the maximum count of ones (1). So, the answer is [0,1]. 
//Example 2:
//Input: mat = [[0,0,0],[0,1,1]]
//Output: [1,2]
//Explanation: The row indexed 1 has the maximum count of ones (2). So we return its index, 1, and the count. So, the answer is [1,2].
//Example 3:
//Input: mat = [[0,0],[1,1],[0,0]]
//Output: [1,2]
//Explanation: The row indexed 1 has the maximum count of ones (2). So the answer is [1,2].
// 
//Constraints:
//	m == mat.length 
//	n == mat[i].length 
//	1 <= m, n <= 100 
//	mat[i][j] is either 0 or 1.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rowAndMaximumOnes(int** mat, int matSize, int* matColSize, int* returnSize){
int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    int *a = (int*)malloc(sizeof(int) * 2);
    int *c = (int*)calloc(matSize, sizeof(int));
    for (i = 0; i < matSize; i++) {
        for (j = 0; j < matColSize[i]; j++) {
            if (mat[i][j] == 1) {
                c[i]++;
            }
        }
    }
    for (i = 0; i < matSize; i++) {
        if (c[i] > n) {
            n = c[i];
            m = i;
        }
    }
    *returnSize = 2;
    a[0] = m;
    a[1] = n;
    return a;
}