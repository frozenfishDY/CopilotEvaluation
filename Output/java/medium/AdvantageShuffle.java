/**https://leetcode.com/problems/advantage-shuffle/ */
//You are given two integer arrays nums1 and nums2 both of the same length. The advantage of nums1 with respect to nums2 is the number of indices i for which nums1[i] > nums2[i].
//Return any permutation of nums1 that maximizes its advantage with respect to nums2.


class AdvantageShuffle {
    public int[] advantageCount(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int[] res = new int[n];
        Arrays.sort(nums1);
        for(int i = 0; i < n; i++){
            int j = binarySearch(nums1, nums2[i]);
            res[i] = nums1[j];
            nums1[j] = -1;
        }
        int k = 0;
        for(int i = 0; i < n; i++){
            if(nums1[i] != -1){
                res[k++] = nums1[i];
            }
        }
        return res;
        
        
        
    }
}

    