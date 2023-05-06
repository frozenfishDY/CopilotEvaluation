/**https://leetcode.com/problems/sum-of-subsequence-widths/ */
//The width of a sequence is the difference between the maximum and minimum elements in the sequence.
//Given an array of integers nums, return the sum of the widths of all the non-empty subsequences of nums. Since the answer may be very large, return it modulo 109 + 7.
//A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].


/**
 * @param {number[]} nums
 * @return {number}
 */
var sumSubseqWidths = function(nums) {
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

    