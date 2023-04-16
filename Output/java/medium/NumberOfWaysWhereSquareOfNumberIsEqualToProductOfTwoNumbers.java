/**https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/ */
//Given two arrays of integers nums1 and nums2, return the number of triplets formed (type 1 and type 2) under the following rules:
//Type 1: Triplet (i, j, k) if nums1[i]2 == nums2[j] * nums2[k] where 0 <= i < nums1.length and 0 <= j < k < nums2.length.
//Type 2: Triplet (i, j, k) if nums2[i]2 == nums1[j] * nums1[k] where 0 <= i < nums2.length and 0 <= j < k < nums1.length.


class NumberOfWaysWhereSquareOfNumberIsEqualToProductOfTwoNumbers {
    public int numTriplets(int[] nums1, int[] nums2) {
        int count = 0;
        for(int i = 0; i < nums1.length; i++){
            for(int j = i + 1; j < nums1.length; j++){
                long product = (long)nums1[i] * nums1[j];
                for(int k = 0; k < nums2.length; k++){
                    if(product == (long)nums2[k] * nums2[k]){
                        count++;
                    }
                }
            }
        }
        for(int i = 0; i < nums2.length; i++){
            for(int j = i + 1; j < nums2.length; j++){
                long product = (long)nums2[i] * nums2[j];
                for(int k = 0; k < nums1.length; k++){
                    if(product == (long)nums1[k] * nums1[k]){
                        count++;
                    }
                }
            }
        }
        return count;
        
    }
}
     
    