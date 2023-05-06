/**https://leetcode.com/problems/number-of-great-partitions/ */
//You are given an array nums consisting of positive integers and an integer k.
//Partition the array into two ordered groups such that each element is in exactly one group. A partition is called great if the sum of elements of each group is greater than or equal to k.
//Return the number of distinct great partitions. Since the answer may be too large, return it modulo 109 + 7.
//Two partitions are considered distinct if some element nums[i] is in different groups in the two partitions.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var countPartitions = function(nums, k) {
    let mod = 1000000007;
    let sum = 0;
    let ans = 0;
    let dp = new Array(nums.length + 1).fill(0);
    dp[0] = 1;
    for(let i = 0; i < nums.length; i++){
        sum += nums[i];
        for(let j = i; j >= 0; j--){
            if(sum - nums[j] >= k){
                dp[i + 1] = (dp[i + 1] + dp[j]) % mod;
            }
        }
        if(sum >= k){
            ans = (ans + dp[i + 1]) % mod;
        }
    }
    return ans;
    
};

    