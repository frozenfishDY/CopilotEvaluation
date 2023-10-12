/**https://leetcode.com/problems/longest-subsequence-with-limited-sum/ */
//You are given an integer array nums of length n, and an integer array queries of length m.
//Return an array answer of length m where answer[i] is the maximum size of a subsequence that you can take from nums such that the sum of its elements is less than or equal to queries[i].
//A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
// 
//Example 1:
//Input: nums = [4,5,2,1], queries = [3,10,21]
//Output: [2,3,4]
//Explanation: We answer the queries as follows:
//- The subsequence [2,1] has a sum less than or equal to 3. It can be proven that 2 is the maximum size of such a subsequence, so answer[0] = 2.
//- The subsequence [4,5,1] has a sum less than or equal to 10. It can be proven that 3 is the maximum size of such a subsequence, so answer[1] = 3.
//- The subsequence [4,5,2,1] has a sum less than or equal to 21. It can be proven that 4 is the maximum size of such a subsequence, so answer[2] = 4.
//Example 2:
//Input: nums = [2,3,4,5], queries = [1]
//Output: [0]
//Explanation: The empty subsequence is the only subsequence that has a sum less than or equal to 1, so answer[0] = 0.
// 
//Constraints:
//	n == nums.length
//	m == queries.length
//	1 <= n, m <= 1000
//	1 <= nums[i], queries[i] <= 106
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* answerQueries(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize){
int *res = (int*)calloc(queriesSize, sizeof(int));
    int i = 0, j = 0, k = 0;
    int *dp = (int*)calloc(numsSize, sizeof(int));
    for (; i < numsSize; i++) {
        dp[i] = 1;
        for (j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = fmax(dp[i], dp[j] + 1);
            }
        }
    }
    for (i = 0; i < queriesSize; i++) {
        for (j = 0; j < numsSize; j++) {
            if (nums[j] <= queries[i]) {
                res[i] = fmax(res[i], dp[j]);
            }
        }
    }
    *returnSize = queriesSize;
    return res;
}