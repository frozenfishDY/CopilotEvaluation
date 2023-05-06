/**https://leetcode.com/problems/maximum-length-of-repeated-subarray/ */
//Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.


/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findLength = function(nums1, nums2) {
    let n = nums1.length;
    let m = nums2.length;
    let dp = new Array(n + 1).fill(0).map(() => new Array(m + 1).fill(0));
    let result = 0;
    for(let i = 1; i <= n; i++){
        for(let j = 1; j <= m; j++){
            if(nums1[i - 1] == nums2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
                result = Math.max(result, dp[i][j]);
            }
        }
    }
    return result;
    
};

    