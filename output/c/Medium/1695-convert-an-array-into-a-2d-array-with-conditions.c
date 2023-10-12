/**https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/ */
//You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:
//	The 2D array should contain only the elements of the array nums.
//	Each row in the 2D array contains distinct integers.
//	The number of rows in the 2D array should be minimal.
//Return the resulting array. If there are multiple answers, return any of them.
//Note that the 2D array can have a different number of elements on each row.
// 
//Example 1:
//Input: nums = [1,3,4,1,2,3,1]
//Output: [[1,3,4,2],[1,3],[1]]
//Explanation: We can create a 2D array that contains the following rows:
//- 1,3,4,2
//- 1,3
//- 1
//All elements of nums were used, and each row of the 2D array contains distinct integers, so it is a valid answer.
//It can be shown that we cannot have less than 3 rows in a valid array.
//Example 2:
//Input: nums = [1,2,3,4]
//Output: [[4,3,2,1]]
//Explanation: All elements of the array are distinct, so we can keep all of them in the first row of the 2D array.
// 
//Constraints:
//	1 <= nums.length <= 200
//	1 <= nums[i] <= nums.length
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findMatrix(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
int i, j;
	*returnSize = 0;
	int** result = (int**)malloc(sizeof(int*));
	*returnColumnSizes = (int*)malloc(sizeof(int));
	int* dp = (int*)malloc(sizeof(int) * (numsSize + 1));
	dp[0] = 0;
	for (i = 0; i < numsSize; i++) {
		dp[i + 1] = dp[i] ^ nums[i];
	}
	int len;
	for (i = 0; i < numsSize; i++) {
		for (j = i + 1; j <= numsSize; j++) {
			if (dp[i] == dp[j]) {
				len = j - i;
				result[*returnSize] = (int*)malloc(sizeof(int) * len);
				(*returnColumnSizes)[*returnSize] = len;
				for (int k = 0; k < len; k++) {
					result[*returnSize][k] = nums[i + k];
				}
				(*returnSize)++;
			}
		}
	}
	return result;
}