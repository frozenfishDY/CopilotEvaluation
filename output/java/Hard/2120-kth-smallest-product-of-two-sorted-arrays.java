/**https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/ */
//Given two sorted 0-indexed integer arrays nums1 and nums2 as well as an integer k, return the kth (1-based) smallest product of nums1[i] * nums2[j] where 0 <= i < nums1.length and 0 <= j < nums2.length.


class KthSmallestProductOfTwoSortedArrays {
    public long kthSmallestProduct(int[] nums1, int[] nums2, long k) {
        int n = nums1.length;
        int m = nums2.length;
        long l = (long)nums1[0] * nums2[0];
        long r = (long)nums1[n - 1] * nums2[m - 1];
        while(l < r){
            long mid = l + r >> 1;
            if(count(nums1, nums2, mid) < k){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return l;
        
        
    }
}
     
    