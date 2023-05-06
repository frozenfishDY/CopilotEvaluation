/**https://leetcode.com/problems/minimum-absolute-sum-difference/ */
//You are given two positive integer arrays nums1 and nums2, both of length n.
//The absolute sum difference of arrays nums1 and nums2 is defined as the sum of |nums1[i] - nums2[i]| for each 0 <= i < n (0-indexed).
//You can replace at most one element of nums1 with any other element in nums1 to minimize the absolute sum difference.
//Return the minimum absolute sum difference after replacing at most one element in the array nums1. Since the answer may be large, return it modulo 109 + 7.
//|x| is defined as:
//x if x >= 0, or
//-x if x < 0.


class MinimumAbsoluteSumDifference {
    public int minAbsoluteSumDiff(int[] nums1, int[] nums2) {
        int mod = 1000000007;
        int[] sorted = nums1.clone();
        Arrays.sort(sorted);
        int sum = 0;
        int max = 0;
        for(int i = 0; i < nums1.length; i++){
            int diff = Math.abs(nums1[i] - nums2[i]);
            sum = (sum + diff) % mod;
            int index = binarySearch(sorted, nums2[i]);
            if(index < nums1.length){
                max = Math.max(max, diff - (sorted[index] - nums2[i]));
            }
            if(index > 0){
                max = Math.max(max, diff - (nums2[i] - sorted[index - 1]));
            }
        }
        return (sum - max + mod) % mod;
        
    }
}
     
    