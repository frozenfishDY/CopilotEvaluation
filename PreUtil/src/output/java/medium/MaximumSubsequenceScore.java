/**https://leetcode.com/problems/maximum-subsequence-score/ */
//You are given two 0-indexed integer arrays nums1 and nums2 of equal length n and a positive integer k. You must choose a subsequence of indices from nums1 of length k.
//For chosen indices i0, i1, ..., ik - 1, your score is defined as:
//The sum of the selected elements from nums1 multiplied with the minimum of the selected elements from nums2.
//It can defined simply as: (nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]).
//Return the maximum possible score.
//A subsequence of indices of an array is a set that can be derived from the set {0, 1, ..., n-1} by deleting some or no elements.


class MaximumSubsequenceScore {
    public long maxScore(int[] nums1, int[] nums2, int k) {
        long res = 0;
        for(int i = 0; i <= k; i++){
            if(i <= nums1.length && k - i <= nums2.length){
                res = Math.max(res, maxScore(nums1, nums2, i) + maxScore(nums2, nums1, k - i));
            }
        }
        return res;
        
        
    }
}

    