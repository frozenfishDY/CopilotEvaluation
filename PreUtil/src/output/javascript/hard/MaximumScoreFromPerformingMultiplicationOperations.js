/**https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/ */
//You are given two 0-indexed integer arrays nums and multipliers of size n and m respectively, where n >= m.
//You begin with a score of 0. You want to perform exactly m operations. On the ith operation (0-indexed) you will:
//Choose one integer x from either the start or the end of the array nums.
//Add multipliers[i] * x to your score.
//Note that multipliers[0] corresponds to the first operation, multipliers[1] to the second operation, and so on.
//Remove x from nums.
//Return the maximum score after performing m operations.


/**
 * @param {number[]} nums
 * @param {number[]} multipliers
 * @return {number}
 */
var maximumScore = function(nums, multipliers) {
    let n = nums.length;
    let m = multipliers.length;
    let dp = new Array(m + 1).fill(0);
    for(let i = 1; i <= m; i++){
        for(let j = i; j >= 0; j--){
            if(j == 0){
                dp[j] = dp[j] + nums[n - i] * multipliers[i - 1];
            }else if(j == i){
                dp[j] = dp[j - 1] + nums[j - 1] * multipliers[i - 1];
            }else{
                dp[j] = Math.max(dp[j] + nums[n - i + j] * multipliers[i - 1], dp[j - 1] + nums[j - 1] * multipliers[i - 1]);
            }
        }
    }
    return Math.max(...dp);
    
};

    