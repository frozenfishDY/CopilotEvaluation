/**https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/ */
//You are given a 0-indexed array nums of length n, consisting of non-negative integers. For each index i from 0 to n - 1, you must determine the size of the minimum sized non-empty subarray of nums starting at i (inclusive) that has the maximum possible bitwise OR.
//	In other words, let Bij be the bitwise OR of the subarray nums[i...j]. You need to find the smallest subarray starting at i, such that bitwise OR of this subarray is equal to max(Bik) where i <= k <= n - 1.
//The bitwise OR of an array is the bitwise OR of all the numbers in it.
//Return an integer array answer of size n where answer[i] is the length of the minimum sized subarray starting at i with maximum bitwise OR.
//A subarray is a contiguous non-empty sequence of elements within an array.
// 
//Example 1:
//Input: nums = [1,0,2,1,3]
//Output: [3,3,2,2,1]
//Explanation:
//The maximum possible bitwise OR starting at any index is 3. 
//- Starting at index 0, the shortest subarray that yields it is [1,0,2].
//- Starting at index 1, the shortest subarray that yields the maximum bitwise OR is [0,2,1].
//- Starting at index 2, the shortest subarray that yields the maximum bitwise OR is [2,1].
//- Starting at index 3, the shortest subarray that yields the maximum bitwise OR is [1,3].
//- Starting at index 4, the shortest subarray that yields the maximum bitwise OR is [3].
//Therefore, we return [3,3,2,2,1]. 
//Example 2:
//Input: nums = [1,2]
//Output: [2,1]
//Explanation:
//Starting at index 0, the shortest subarray that yields the maximum bitwise OR is of length 2.
//Starting at index 1, the shortest subarray that yields the maximum bitwise OR is of length 1.
//Therefore, we return [2,1].
// 
//Constraints:
//	n == nums.length
//	1 <= n <= 105
//	0 <= nums[i] <= 109
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallestSubarrays(int* nums, int numsSize, int* returnSize){
int i, j;
	int *cnt = (int *)malloc(sizeof(int) * 1000000001);
	memset(cnt, 0, sizeof(int) * 1000000001);
	for (i = 0; i < numsSize; ++i) {
		cnt[nums[i]]++;
	}
	int max = 0;
	for (i = 0; i < 1000000001; ++i) {
		if (cnt[i] > max) {
			max = cnt[i];
		}
	}
	if (numsSize - max * 2 == 0) {
		*returnSize = numsSize;
		return nums;
	}
	*returnSize = numsSize - max * 2;
	int *ret = (int *)malloc(sizeof(int) * (*returnSize));
	int idx = 0;
	for (i = 0; i < numsSize; ++i) {
		if (cnt[nums[i]] == max) {
			ret[idx++] = nums[i];
		}
	}
	return ret;
}