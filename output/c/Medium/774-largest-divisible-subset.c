/**https://leetcode.com/problems/largest-divisible-subset/ */
//Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
//	answer[i] % answer[j] == 0, or
//	answer[j] % answer[i] == 0
//If there are multiple solutions, return any of them.
// 
//Example 1:
//Input: nums = [1,2,3]
//Output: [1,2]
//Explanation: [1,3] is also accepted.
//Example 2:
//Input: nums = [1,2,4,8]
//Output: [1,2,4,8]
// 
//Constraints:
//	1 <= nums.length <= 1000
//	1 <= nums[i] <= 2 * 109
//	All the integers in nums are unique.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize){
int* res = (int*)malloc(sizeof(int) * numsSize);
	int* dp = (int*)malloc(sizeof(int) * numsSize);
	int max = 0, max_i = 0;
	*returnSize = 0;
	if (numsSize == 0) return res;
	qsort(nums, numsSize, sizeof(int), cmp);
	for (int i = 0; i < numsSize; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
		if (max < dp[i]) {
			max = dp[i];
			max_i = i;
		}
	}
	for (int i = max_i, temp = nums[max_i], j = max - 1; i >= 0; i--) {
		if (temp % nums[i] == 0 && dp[i] == j) {
			res[(*returnSize)++] = nums[i];
			temp = nums[i];
			j--;
		}
	}
	free(dp);
	return res;
}