/**https://leetcode.com/problems/contains-duplicate-iii/ */
//You are given an integer array nums and two integers indexDiff and valueDiff.
//Find a pair of indices (i, j) such that:
//i != j,
//abs(i - j) <= indexDiff.
//abs(nums[i] - nums[j]) <= valueDiff, and
//Return true if such pair exists or false otherwise.


/**
 * @param {number[]} nums
 * @param {number} indexDiff
 * @param {number} valueDiff
 * @return {boolean}
 */
var containsNearbyAlmostDuplicate = function(nums, indexDiff, valueDiff) {
    let n = nums.length;
    let dp = [];
    for(let i = 0; i <= n; i++){
        dp.push([]);
        for(let j = 0; j <= indexDiff; j++){
            dp[i].push([]);
            for(let k = 0; k <= valueDiff; k++){
                dp[i][j].push(false);
            }
        }
    }
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= indexDiff; j++){
            for(let k = 1; k <= valueDiff; k++){
                if(i - j >= 0 && Math.abs(nums[i - 1] - nums[i - j - 1]) <= k){
                    dp[i][j][k] = true;
                }
                else{
                    dp[i][j][k] = dp[i - 1][j][k];
                }
            }
        }
    }
    return dp[n][indexDiff][valueDiff];
    
};

    