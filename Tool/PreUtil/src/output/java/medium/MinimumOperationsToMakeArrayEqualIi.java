/**https://leetcode.com/problems/minimum-operations-to-make-array-equal-ii/ */
//You are given two integer arrays nums1 and nums2 of equal length n and an integer k. You can perform the following operation on nums1:
//Choose two indexes i and j and increment nums1[i] by k and decrement nums1[j] by k. In other words, nums1[i] = nums1[i] + k and nums1[j] = nums1[j] - k.
//nums1 is said to be equal to nums2 if for all indices i such that 0 <= i < n, nums1[i] == nums2[i].
//Return the minimum number of operations required to make nums1 equal to nums2. If it is impossible to make them equal, return -1.


class MinimumOperationsToMakeArrayEqualIi {
    public long minOperations(int[] nums1, int[] nums2, int k) {
        int n = nums1.length;
        int m = nums2.length;
        if(n * 6 < k || m * 6 < k){
            return -1;
        }
        int[] diff = new int[n + m];
        for(int i = 0; i < n; i++){
            diff[i] = nums1[i] - 1;
        }
        for(int i = 0; i < m; i++){
            diff[n + i] = 6 - nums2[i];
        }
        Arrays.sort(diff);
        long res = 0;
        for(int i = 0; i < k; i++){
            res += diff[i];
        }
        return res;
        
        
    }
}

    