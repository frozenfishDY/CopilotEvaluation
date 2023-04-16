/**https://leetcode.com/problems/median-of-two-sorted-arrays/ */
//Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
//The overall run time complexity should be O(log (m+n)).


class MedianOfTwoSortedArrays {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] nums3 = new int[nums1.length + nums2.length];
        int i = 0, j = 0, k = 0;
        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] < nums2[j]) {
                nums3[k] = nums1[i];
                i++;
            } else {
                nums3[k] = nums2[j];
                j++;
            }
            k++;
        }
        while (i < nums1.length) {
            nums3[k] = nums1[i];
            i++;
            k++;
        }
        while (j < nums2.length) {
            nums3[k] = nums2[j];
            j++;
            k++;
        }
        if (nums3.length % 2 == 0) {
            return (nums3[nums3.length / 2] + nums3[nums3.length / 2 - 1]) / 2.0;
        } else {
            return nums3[nums3.length / 2];
        }
        
    }
}
     
    