/**https://leetcode.com/problems/minimum-cost-to-split-an-array/ */
//You are given an integer array nums and an integer k.
//Split the array into some number of non-empty subarrays. The cost of a split is the sum of the importance value of each subarray in the split.
//Let trimmed(subarray) be the version of the subarray where all numbers which appear only once are removed.
//For example, trimmed([3,1,2,4,3,4]) = [3,4,3,4].
//The importance value of a subarray is k + trimmed(subarray).length.
//For example, if a subarray is [1,2,3,3,3,4,4], then trimmed([1,2,3,3,3,4,4]) = [3,3,3,4,4].The importance value of this subarray will be k + 5.
//Return the minimum possible cost of a split of nums.
//A subarray is a contiguous non-empty sequence of elements within an array.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var minCost = function(nums, k) {
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

    