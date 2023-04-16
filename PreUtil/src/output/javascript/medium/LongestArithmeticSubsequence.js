/**https://leetcode.com/problems/longest-arithmetic-subsequence/ */
//Given an array nums of integers, return the length of the longest arithmetic subsequence in nums.
//Note that:
//A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
//A sequence seq is arithmetic if seq[i + 1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).


/**
 * @param {number[]} nums
 * @return {number}
 */
var longestArithSeqLength = function(nums) {
    let n = nums.length;
    let result = 0;
    let dp = new Array(n);
    for(let i = 0; i < n; i++){
        dp[i] = new Map();
    }
    for(let i = 1; i < n; i++){
        for(let j = 0; j < i; j++){
            let diff = nums[i] - nums[j];
            if(dp[j].has(diff)){
                dp[i].set(diff, dp[j].get(diff) + 1);
            }else{
                dp[i].set(diff, 2);
            }
            result = Math.max(result, dp[i].get(diff));
        }
    }
    return result;
    
};

    