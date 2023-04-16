/**https://leetcode.com/problems/split-array-largest-sum/ */
//Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
//Return the minimized largest sum of the split.
//A subarray is a contiguous part of the array.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var splitArray = function(nums, k) {
    let dp = [];
    for(let i = 0; i <= nums.length; i++){
        dp.push([]);
        for(let j = 0; j <= k; j++){
            dp[i].push([]);
            for(let l = 0; l <= nums.length; l++){
                dp[i][j].push(0);
            }
        }
    }
    for(let i = 0; i <= nums.length; i++){
        dp[i][0][0] = 1;
    }
    for(let i = 1; i <= nums.length; i++){
        for(let j = 1; j <= k; j++){
            for(let l = 1; l <= nums.length; l++){
                if(nums[i - 1] > nums[l - 1]){
                    dp[i][j][l] = dp[i - 1][j - 1][l - 1] + dp[i - 1][j][l];
                }else{
                    dp[i][j][l] = dp[i - 1][j][l];
                }
            }
        }
    }
    let ans = [];
    for(let i = 1; i <= nums.length; i++){
        ans.push(dp[nums.length][k][i] - dp[nums.length][k][i - 1]);
    }
    return ans;
    
};

    