/**https://leetcode.com/problems/maximum-subsequence-score/ */
//You are given two 0-indexed integer arrays nums1 and nums2 of equal length n and a positive integer k. You must choose a subsequence of indices from nums1 of length k.
//For chosen indices i0, i1, ..., ik - 1, your score is defined as:
//The sum of the selected elements from nums1 multiplied with the minimum of the selected elements from nums2.
//It can defined simply as: (nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]).
//Return the maximum possible score.
//A subsequence of indices of an array is a set that can be derived from the set {0, 1, ..., n-1} by deleting some or no elements.


long long maxScore(int* nums1, int nums1Size, int* nums2, int nums2Size, int k){
    long long result = 0;
    for(int i = 0; i <= k; i++){
        if(i <= nums1Size && k - i <= nums2Size){
            long long sum1 = 0;
            long long sum2 = 0;
            for(int j = 0; j < i; j++){
                sum1 += nums1[j];
            }
            for(int j = 0; j < k - i; j++){
                sum2 += nums2[j];
            }
            long long min = sum2;
            for(int j = k - i; j < nums2Size; j++){
                sum2 += nums2[j];
                sum2 -= nums2[j - k + i];
                if(sum2 < min){
                    min = sum2;
                }
            }
            if(sum1 * min > result){
                result = sum1 * min;
            }
        }
    }
    return result;

}

    