/**https://leetcode.com/problems/minimum-total-cost-to-make-arrays-unequal/ */
//You are given two 0-indexed integer arrays nums1 and nums2, of equal length n.
//In one operation, you can swap the values of any two indices of nums1. The cost of this operation is the sum of the indices.
//Find the minimum total cost of performing the given operation any number of times such that nums1[i] != nums2[i] for all 0 <= i <= n - 1 after performing all the operations.
//Return the minimum total cost such that nums1 and nums2 satisfy the above condition. In case it is not possible, return -1.


class MinimumTotalCostToMakeArraysUnequal {
    public long minimumTotalCost(int[] nums1, int[] nums2) {
        int n = nums1.length;
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        long res = Long.MAX_VALUE;
        for(int i = 0; i < n; i++){
            int j = Arrays.binarySearch(nums2, nums1[i]);
            if(j < 0){
                j = -j - 1;
            }
            long cost = 0;
            for(int k = 0; k < n; k++){
                if(k != i){
                    cost += Math.min(Math.abs(nums1[k] - nums1[i]), Math.abs(nums2[k] - nums1[i]));
                }
            }
            res = Math.min(res, cost);
            if(j < n){
                cost = 0;
                for(int k = 0; k < n; k++){
                    if(k != i){
                        cost += Math.min(Math.abs(nums1[k] - nums2[i]), Math.abs(nums2[k] - nums2[i]));
                    }
                }
                res = Math.min(res, cost);
            }
        }
        return res;
        
    }
}
     
    