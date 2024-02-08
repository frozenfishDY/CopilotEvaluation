/**https://leetcode.com/problems/create-maximum-number/ */
//You are given two integer arrays nums1 and nums2 of lengths m and n respectively. nums1 and nums2 represent the digits of two numbers. You are also given an integer k.
//Create the maximum number of length k <= m + n from digits of the two numbers. The relative order of the digits from the same array must be preserved.
//Return an array of the k digits representing the answer.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * k);
    int* queue = (int*)malloc(sizeof(int) * (nums1Size + nums2Size));
    int head = 0, tail = 0;
    for(int i = 0; i < nums1Size + nums2Size; i++){
        while(head < tail && nums1[queue[tail - 1]] < nums1[i]) tail--;
        queue[tail++] = i;
        if(i - queue[head] >= k) head++;
        if(i >= k - 1) result[i - k + 1] = nums1[queue[head]];
    }
    *returnSize = k;
    return result;

}

    