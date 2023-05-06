/**https://leetcode.com/problems/pascals-triangle-ii/ */
//Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
//In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    int *result = (int *)malloc(sizeof(int) * (rowIndex + 1));
    for(int i = 0; i <= rowIndex; i++){
        result[i] = 1;
        for(int j = i - 1; j > 0; j--){
            result[j] = result[j - 1] + result[j];
        }
    }
    *returnSize = rowIndex + 1;
    return result;

}
    