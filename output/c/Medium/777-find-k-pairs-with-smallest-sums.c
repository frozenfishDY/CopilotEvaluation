/**https://leetcode.com/problems/find-k-pairs-with-smallest-sums/ */
//You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
//Define a pair (u, v) which consists of one element from the first array and one element from the second array.
//Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize, int** returnColumnSizes){
    int** result = (int**)malloc(sizeof(int*) * k);
    *returnColumnSizes = (int*)malloc(sizeof(int) * k);
    int resultSize = 0;
    int* nums1Index = (int*)malloc(sizeof(int) * nums1Size);
    int* nums2Index = (int*)malloc(sizeof(int) * nums2Size);
    for(int i = 0; i < nums1Size; i++){
        nums1Index[i] = 0;
    }
    for(int i = 0; i < nums2Size; i++){
        nums2Index[i] = 0;
    }
    for(int i = 0; i < k; i++){
        int min = INT_MAX;
        int minIndex = -1;
        for(int j = 0; j < nums1Size; j++){
            if(nums1Index[j] < nums2Size && nums1[j] + nums2[nums1Index[j]] < min){
                min = nums1[j] + nums2[nums1Index[j]];
                minIndex = j;
            }
        }
        if(minIndex == -1){
            break;
        }
        result[resultSize] = (int*)malloc(sizeof(int) * 2);
        result[resultSize][0] = nums1[minIndex];
        result[resultSize][1] = nums2[nums1Index[minIndex]];
        (*returnColumnSizes)[resultSize] = 2;
        resultSize++;
        nums1Index[minIndex]++;
    }
    *returnSize = resultSize;
    return result;

}

    