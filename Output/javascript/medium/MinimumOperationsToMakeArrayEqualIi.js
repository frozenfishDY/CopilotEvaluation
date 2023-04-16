/**https://leetcode.com/problems/minimum-operations-to-make-array-equal-ii/ */
//You are given two integer arrays nums1 and nums2 of equal length n and an integer k. You can perform the following operation on nums1:
//Choose two indexes i and j and increment nums1[i] by k and decrement nums1[j] by k. In other words, nums1[i] = nums1[i] + k and nums1[j] = nums1[j] - k.
//nums1 is said to be equal to nums2 if for all indices i such that 0 <= i < n, nums1[i] == nums2[i].
//Return the minimum number of operations required to make nums1 equal to nums2. If it is impossible to make them equal, return -1.


/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @param {number} k
 * @return {number}
 */
var minOperations = function(nums1, nums2, k) {
    let n = nums1.length;
    let m = nums2.length;
    if(n * 6 < k || m * 6 < k){
        return -1;
    }
    let sum1 = 0;
    let sum2 = 0;
    for(let i = 0; i < n; i++){
        sum1 += nums1[i];
    }
    for(let i = 0; i < m; i++){
        sum2 += nums2[i];
    }
    if(sum1 > sum2){
        return minOperations(nums2, nums1, k);
    }
    let diff = sum2 - sum1;
    let dp = new Array(k + 1).fill(0);
    for(let i = 0; i <= k; i++){
        dp[i] = new Array(diff + 1).fill(-1);
    }
    let result = helper(nums1, nums2, k, diff, 0, 0, dp);
    return result == Number.MAX_SAFE_INTEGER ? -1 : result;
    
    
};

    