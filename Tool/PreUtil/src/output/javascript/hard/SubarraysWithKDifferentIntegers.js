/**https://leetcode.com/problems/subarrays-with-k-different-integers/ */
//Given an integer array nums and an integer k, return the number of good subarrays of nums.
//A good array is an array where the number of different integers in that array is exactly k.
//For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
//A subarray is a contiguous part of an array.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraysWithKDistinct = function(nums, k) {
    let dp = [];
    for(let i = 0; i <= nums.length; i++){
        dp.push([]);
        for(let j = 0; j <= nums.length; j++){
            dp[i].push(0);
        }
    }
    for(let i = 0; i <= nums.length; i++){
        dp[i][0] = 1;
    }
    for(let i = 1; i <= nums.length; i++){
        for(let j = 1; j <= nums.length; j++){
            if(i > j){
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    let ans = [];
    for(let i = 1; i <= nums.length; i++){
        ans.push(dp[nums.length][i] - dp[nums.length][i - 1]);
    }
    return ans;
    
    
};

    