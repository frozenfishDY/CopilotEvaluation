/**https://leetcode.com/problems/minimum-common-value/ */
//Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.
//Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.


class MinimumCommonValue {
    public int getCommon(int[] nums1, int[] nums2) {
        int i = 0;
        int j = 0;
        while(i < nums1.length && j < nums2.length){
            if(nums1[i] == nums2[j]){
                return nums1[i];
            }else if(nums1[i] < nums2[j]){
                i++;
            }else{
                j++;
            }
        }
        return -1;
        
        
    }
}

    