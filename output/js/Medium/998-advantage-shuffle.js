/**https://leetcode.com/problems/advantage-shuffle/ */
//You are given two integer arrays nums1 and nums2 both of the same length. The advantage of nums1 with respect to nums2 is the number of indices i for which nums1[i] > nums2[i].
//Return any permutation of nums1 that maximizes its advantage with respect to nums2.


/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var advantageCount = function(nums1, nums2) {
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

    