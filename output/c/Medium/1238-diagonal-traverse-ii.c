/**https://leetcode.com/problems/diagonal-traverse-ii/ */
//Given a 2D integer array nums, return all elements of nums in diagonal order as shown in the below images.
// 
//Example 1:
//Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [1,4,2,7,5,3,8,6,9]
//Example 2:
//Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
//Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i].length <= 105
//	1 <= sum(nums[i].length) <= 105
//	1 <= nums[i][j] <= 105
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** nums, int numsSize, int* numsColSize, int* returnSize){
int i, j, k, max, max_index;
    int *result = (int *)malloc(sizeof(int) * (numsSize * numsColSize[0]));
    memset(result, 0, sizeof(int) * (numsSize * numsColSize[0]));
    for(i = 0; i < numsSize; i++)
    {
        for(j = 0; j < numsColSize[i]; j++)
        {
            result[i + j] = nums[i][j];
        }
    }
    *returnSize = numsSize * numsColSize[0];
    return result;
}