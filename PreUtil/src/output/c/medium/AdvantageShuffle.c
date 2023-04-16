/**https://leetcode.com/problems/advantage-shuffle/ */
//You are given two integer arrays nums1 and nums2 both of the same length. The advantage of nums1 with respect to nums2 is the number of indices i for which nums1[i] > nums2[i].
//Return any permutation of nums1 that maximizes its advantage with respect to nums2.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* advantageCount(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * nums1Size);
    *returnSize = nums1Size;
    int* hash = (int*)malloc(sizeof(int) * nums1Size);
    for(int i = 0; i < nums1Size; i++){
        hash[i] = -1;
    }
    for(int i = 0; i < nums1Size; i++){
        int max = -1;
        int maxIndex = -1;
        for(int j = 0; j < nums1Size; j++){
            if(nums1[j] > max && hash[j] == -1){
                max = nums1[j];
                maxIndex = j;
            }
        }
        hash[maxIndex] = i;
    }
    for(int i = 0; i < nums1Size; i++){
        int max = -1;
        int maxIndex = -1;
        for(int j = 0; j < nums1Size; j++){
            if(nums1[j] > max && hash[j] == -1 && nums1[j] > nums2[i]){
                max = nums1[j];
                maxIndex = j;
            }
        }
        if(maxIndex == -1){
            for(int j = 0; j < nums1Size; j++){
                if(nums1[j] > max && hash[j] == -1){
                    max = nums1[j];
                    maxIndex = j;
                }
            }
        }
        result[hash[maxIndex]] = nums1[maxIndex];
        hash[maxIndex] = -1;
    }
    return result;

}

    