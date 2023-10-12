/**https://leetcode.com/problems/non-decreasing-subsequences/ */
//Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.
// 
//Example 1:
//Input: nums = [4,6,7,7]
//Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
//Example 2:
//Input: nums = [4,4,3,2,1]
//Output: [[4,4]]
// 
//Constraints:
//	1 <= nums.length <= 15
//	-100 <= nums[i] <= 100
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findSubsequences(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
int** res = (int**)malloc(sizeof(int*) * 20000);
	*returnColumnSizes = (int*)malloc(sizeof(int) * 20000);
	int* temp = (int*)malloc(sizeof(int) * numsSize);
	*returnSize = 0;
	dfs(nums, numsSize, 0, temp, 0, res, returnSize, returnColumnSizes);
	return res;
}

void dfs(int* nums, int numsSize, int index, int* temp, int tempSize, int** res, int* returnSize, int** returnColumnSizes) {
	if (tempSize >= 2) {
		res[*returnSize] = (int*)malloc(sizeof(int) * tempSize);
		(*returnColumnSizes)[*returnSize] = tempSize;
		for (int i = 0; i < tempSize; i++) {
			res[*returnSize][i] = temp[i];
		}
		(*returnSize)++;
	}
	if (index == numsSize) {
		return;
	}
	int visited[201] = {0};
	for (int i = index; i < numsSize; i++) {
		if (visited[nums[i] + 100] == 1) {
			continue;
		}
		if (tempSize == 0 || nums[i] >= temp[tempSize - 1]) {
			visited[nums[i] + 100] = 1;
			temp[tempSize] = nums[i];
			dfs(nums, numsSize, i + 1, temp, tempSize + 1, res, returnSize, returnColumnSizes);
		}
	}
}