/**https://leetcode.com/problems/find-a-peak-element-ii/ */
//A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.
//Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].
//You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.
//You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.
// 
//Example 1:
//Input: mat = [[1,4],[3,2]]
//Output: [0,1]
//Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.
//Example 2:
//Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
//Output: [1,1]
//Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 500
//	1 <= mat[i][j] <= 105
//	No two adjacent cells are equal.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findPeakGrid(int** mat, int matSize, int* matColSize, int* returnSize){
int i,j;
    int m=matSize;
    int n=*matColSize;
    int *res=(int *)malloc(sizeof(int)*2);
    int max=0;
    int max_i=0;
    int max_j=0;
    int flag=0;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(mat[i][j]>max){
                max=mat[i][j];
                max_i=i;
                max_j=j;
            }
        }
    }
    int temp_i=max_i;
    int temp_j=max_j;
    while(temp_i>0 && mat[temp_i][temp_j]>mat[temp_i-1][temp_j]){
        temp_i--;
    }
    if(temp_i==0){
        res[0]=temp_i;
        res[1]=temp_j;
        *returnSize=2;
        return res;
    }
    temp_i=max_i;
    temp_j=max_j;
    while(temp_i<m-1 && mat[temp_i][temp_j]>mat[temp_i+1][temp_j]){
        temp_i++;
    }
    if(temp_i==m-1){
        res[0]=temp_i;
        res[1]=temp_j;
        *returnSize=2;
        return res;
    }
    temp_i=max_i;
    temp_j=max_j;
    while(temp_j>0 && mat[temp_i][temp_j]>mat[temp_i][temp_j-1]){
        temp_j--;
    }
    if(temp_j==0){
        res[0]=temp_i;
        res[1]=temp_j;
        *returnSize=2;
        return res;
    }
    temp_i=max_i;
    temp_j=max_j;
    while(temp_j<n-1 && mat[temp_i][temp_j]>mat[temp_i][temp_j+1]){
        temp_j++;
    }
    if(temp_j==n-1){
        res[0]=temp_i;
        res[1]=temp_j;
        *returnSize=2;
        return res;
    }
    res[0]=max_i;
    res[1]=max_j;
    *returnSize=2;
    return res;
}