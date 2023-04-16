/**https://leetcode.com/problems/max-dot-product-of-two-subsequences/ */
//Given two arrays nums1 and nums2.
//Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.
//A subsequence of a array is a new array which is formed from the original array by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is not).


/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var maxDotProduct = function(nums1, nums2) {
    let n = nums1.length;
    let m = nums2.length;
    let dp = new Array(n + 1).fill(0).map(() => new Array(m + 1).fill(-Infinity));
    dp[0][0] = 0;
    let ans = -Infinity;
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= m; j++){
            dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1] + nums1[i - 1] * nums2[j - 1], nums1[i - 1] * nums2[j - 1]);
            dp[i][j] = Math.max(dp[i][j], dp[i - 1][j], dp[i][j - 1]);
            ans = Math.max(ans, dp[i][j]);
        }
    }
    return ans;
    
};

    