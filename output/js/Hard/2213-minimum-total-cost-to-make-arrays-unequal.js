/**https://leetcode.com/problems/minimum-total-cost-to-make-arrays-unequal/ */
//You are given two 0-indexed integer arrays nums1 and nums2, of equal length n.
//In one operation, you can swap the values of any two indices of nums1. The cost of this operation is the sum of the indices.
//Find the minimum total cost of performing the given operation any number of times such that nums1[i] != nums2[i] for all 0 <= i <= n - 1 after performing all the operations.
//Return the minimum total cost such that nums1 and nums2 satisfy the above condition. In case it is not possible, return -1.


/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var minimumTotalCost = function(nums1, nums2) {
    let n = nums1.length;
    let dp = new Array(n + 1).fill(Infinity);
    dp[0] = 0;
    for(let i = 0; i < n; i++){
        let next = new Array(n + 1).fill(Infinity);
        for(let j = 0; j <= n; j++){
            if(nums1[i] != nums2[i]){
                next[j] = Math.min(next[j], dp[j] + i);
            }
            if(j < n && nums1[i] != nums2[j]){
                next[j + 1] = Math.min(next[j + 1], dp[j] + j);
            }
            if(j < n && nums1[j] != nums2[i]){
                next[j + 1] = Math.min(next[j + 1], dp[j] + i);
            }
        }
        dp = next;
    }
    return dp[n] == Infinity ? -1 : dp[n];
    
};

    