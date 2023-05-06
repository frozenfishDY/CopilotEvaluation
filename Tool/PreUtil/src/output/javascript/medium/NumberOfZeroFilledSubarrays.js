/**https://leetcode.com/problems/number-of-zero-filled-subarrays/ */
//Given an integer array nums, return the number of subarrays filled with 0.
//A subarray is a contiguous non-empty sequence of elements within an array.


/**
 * @param {number[]} nums
 * @return {number}
 */
var zeroFilledSubarray = function(nums) {
    let n = nums.length;
    let dp = new Array(n).fill(0).map(() => new Array(2).fill(0));
    let res = 0;
    for (let i = 0; i < n; i++) {
        if (nums[i] === 0) {
            dp[i][0] = 1;
            if (i > 0) {
                dp[i][1] = dp[i - 1][0] + 1;
            }
        }
        res += dp[i][1];
    }
    return res;
    
};

    