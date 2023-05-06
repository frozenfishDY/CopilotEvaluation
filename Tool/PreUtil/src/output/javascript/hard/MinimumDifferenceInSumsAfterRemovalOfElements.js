/**https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/ */
//You are given a 0-indexed integer array nums consisting of 3 * n elements.
//You are allowed to remove any subsequence of elements of size exactly n from nums. The remaining 2 * n elements will be divided into two equal parts:
//The first n elements belonging to the first part and their sum is sumfirst.
//The next n elements belonging to the second part and their sum is sumsecond.
//The difference in sums of the two parts is denoted as sumfirst - sumsecond.
//For example, if sumfirst = 3 and sumsecond = 2, their difference is 1.
//Similarly, if sumfirst = 2 and sumsecond = 3, their difference is -1.
//Return the minimum difference possible between the sums of the two parts after the removal of n elements.


/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumDifference = function(nums) {
    let n = nums.length / 3;
    let dp = new Array(n + 1);
    for(let i = 0; i < dp.length; i++){
        dp[i] = new Array(n + 1).fill(0);
    }
    let sum = new Array(n + 1);
    sum[0] = 0;
    for(let i = 1; i <= n; i++){
        sum[i] = sum[i - 1] + nums[i - 1];
    }
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= n; j++){
            dp[i][j] = Math.min(dp[i - 1][j] + nums[i + j - 1], dp[i][j - 1] + nums[i + j - 1]);
        }
    }
    let ans = Number.MAX_SAFE_INTEGER;
    for(let i = 0; i <= n; i++){
        ans = Math.min(ans, Math.abs(sum[n] - 2 * dp[i][n - i]));
    }
    return ans;
    
};

    