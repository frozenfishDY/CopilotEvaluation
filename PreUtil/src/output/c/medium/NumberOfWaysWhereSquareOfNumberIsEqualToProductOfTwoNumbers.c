/**https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/ */
//Given two arrays of integers nums1 and nums2, return the number of triplets formed (type 1 and type 2) under the following rules:
//Type 1: Triplet (i, j, k) if nums1[i]2 == nums2[j] * nums2[k] where 0 <= i < nums1.length and 0 <= j < k < nums2.length.
//Type 2: Triplet (i, j, k) if nums2[i]2 == nums1[j] * nums1[k] where 0 <= i < nums2.length and 0 <= j < k < nums1.length.


int numTriplets(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int i, j, k, count = 0;
    for(i = 0; i < nums1Size; i++){
        for(j = 0; j < nums2Size - 1; j++){
            for(k = j + 1; k < nums2Size; k++){
                if(nums1[i] * nums1[i] == nums2[j] * nums2[k]){
                    count++;
                }
            }
        }
    }
    for(i = 0; i < nums2Size; i++){
        for(j = 0; j < nums1Size - 1; j++){
            for(k = j + 1; k < nums1Size; k++){
                if(nums2[i] * nums2[i] == nums1[j] * nums1[k]){
                    count++;
                }
            }
        }
    }
    return count;

}

    