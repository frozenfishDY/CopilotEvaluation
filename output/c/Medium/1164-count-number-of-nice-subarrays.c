/**https://leetcode.com/problems/count-number-of-nice-subarrays/ */
//Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it._x000D_
//_x000D_
//Return the number of nice sub-arrays._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: nums = [1,1,2,1,1], k = 3_x000D_
//Output: 2_x000D_
//Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1]._x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//Input: nums = [2,4,6], k = 1_x000D_
//Output: 0_x000D_
//Explanation: There is no odd numbers in the array._x000D_
//_x000D_
//_x000D_
//Example 3:_x000D_
//_x000D_
//_x000D_
//Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2_x000D_
//Output: 16_x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	1 <= nums.length <= 50000_x000D_
//	1 <= nums[i] <= 10^5_x000D_
//	1 <= k <= nums.length_x000D_
int numberOfSubarrays(int* nums, int numsSize, int k){
int *dp = (int *)malloc(sizeof(int) * (numsSize + 1));
    memset(dp, 0, sizeof(int) * (numsSize + 1));
    int res = 0;
    int sum = 0;
    dp[0] = 1;
    for (int i = 0; i < numsSize; ++i) {
        sum += nums[i] % 2;
        if (sum - k >= 0) {
            res += dp[sum - k];
        }
        dp[sum]++;
    }
    return res;
}