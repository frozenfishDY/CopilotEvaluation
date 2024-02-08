/**https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/ */
//You are given a binary array nums and an integer k.
//A k-bit flip is choosing a subarray of length k from nums and simultaneously changing every 0 in the subarray to 1, and every 1 in the subarray to 0.
//Return the minimum number of k-bit flips required so that there is no 0 in the array. If it is not possible, return -1.
//A subarray is a contiguous part of an array.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var minKBitFlips = function(nums, k) {
    let n = nums.length;
    let dp = [];
    for(let i = 0; i <= n; i++){
        dp.push([]);
        for(let j = 0; j <= n; j++){
            dp[i].push(0);
        }
    }
    for(let i = 0; i <= n; i++){
        dp[i][i] = 1;
    }
    for(let i = 1; i <= n; i++){
        for(let j = i - 1; j >= 0; j--){
            if(s[i - 1] === s[j]){
                dp[i][j] = dp[i - 1][j];
            }else{
                dp[i][j] = Math.min(dp[i - 1][j], dp[i][j + 1]) + 1;
            }
        }
    }
    return dp[n][0];
    
};

    